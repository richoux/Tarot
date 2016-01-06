/*
 * Tarot is an application for Android system to play to French Tarot.
 * Please visit https://github.com/richoux/Tarot for further information.
 * 
 * Copyright (C) 2013-2016 Florian Richoux
 *
 * This file is part of Tarot.
 * Tarot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Tarot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Tarot.  If not, see http://www.gnu.org/licenses/.
 */

#include <iostream>
#include <cstdlib>
#include <utility>

#include "Game.hpp"

Game::Game()
  : currentTrick(make_shared<Trick>()),
    indexToBid(-1),
    indexBidder(0),
    kingFound(false),
    chelemAnnounced(false),
    addDogAtTheEnd(false),
    toSwap(false),
    botsOnly(false),
    foolGiver(nullptr),
    foolReceiver(nullptr)
{}

Game::Game( int& numberPlayers, const string yourName, const bool automatic )
  : currentTrick(make_shared<Trick>()),
    indexToBid(-1),
    indexBidder(0),
    kingFound(false),
    chelemAnnounced(false),
    addDogAtTheEnd(false),
    toSwap(false),
    foolGiver(nullptr),
    foolReceiver(nullptr)
{
  setGame( numberPlayers, yourName, automatic );
}

/////////
// public

void Game::chooseKing()
{
  kingCalled = takers.members.begin()->second->chooseKing( deck );
}

void Game::closeBiddings( const Biddings bestBid )
{
  bidding = bestBid;
  
  takers.members[ players[indexBidder]->name ] = players[indexBidder];
  if( players.size() < 5 )
  {
    for( unsigned int i = 0; i < players.size(); i++ )
      if( i != indexBidder )
	defenders.members[ players[i]->name ] = players[i];
  }
  else
  {
    for( unsigned int i = 0; i < players.size(); i++ )
      if( i != indexBidder )
	unknown.members[ players[i]->name ] = players[i];
  }
  
  if( !chelemAnnounced )
  {
    indexNext = indexBidder;
    next = players[indexBidder];
  }
}

double Game::computeScore( const string& name ) const
{
  double score = 0;

  for( shared_ptr<Card> card : cardsPlayer.at( name ) )
    score += card->getPoints();
  
  return score;
}

void Game::dealCards()
{
  int indexCard = 0;
  set<int> indexDog;
  int newIndex;

  // choose dogSize number of cards to compose the dog.

  do
  {
    newIndex = rand() % 78;
    indexDog.insert( newIndex );
  }
  while( indexDog.size() < dogSize );

  // deal cards to the dog
  for( auto& dogCardIndex : indexDog )
    dog.insert( deck.cards[ dogCardIndex ] );
  
  // deal cards to players
  for( int round = 0; round < cardsPerPlayer; round += consecutiveDealing )
    for( unsigned int gamers = 0; gamers < players.size(); ++gamers )
    {
      for( int card = 0 ; card < consecutiveDealing ; )
      {
	if( indexDog.find( indexCard ) == indexDog.end() )
	{
	  next->addCard( deck.cards[ indexCard ] );
	  ++card;
	}
	
	++indexCard;
      }
      nextPlayer();
    }
}

Team Game::endGame()
{
  if( toSwap )
    swapFool();
  
  if( addDogAtTheEnd )
    addWonCards( defenders.members.begin()->first, dog );
    
  // Compute score for each player
  for( shared_ptr<Player> player : players )
    player->score = computeScore( player->name );
  
  if( takers > defenders )
    return takers;
  else
    return defenders;
}

set<shared_ptr<Card> > Game::getPlayerWonCards( const shared_ptr<Player> player ) const
{
  return cardsPlayer.at( player->name );
}

shared_ptr<Trick> Game::getTrick()
{
  update();
  return currentTrick;
}

void Game::newGame()
{
  for( shared_ptr<Player> player : players )
  {
    cardsPlayer[player->name].clear();
    player->newGame();    
  }

  dog.clear();
  
  while( !history.empty() )
    history.pop();

  takers.newGame();
  defenders.newGame();
  if( players.size() == 5 )
  {
    unknown.newGame();
    kingFound = false;
  }
  
  foolGiver = foolReceiver = nullptr;
  toSwap = false;
  chelemAnnounced = false;
  if( indexToBid == players.size() - 1 )
    indexToBid = 0;
  else
    ++indexToBid;
}

shared_ptr< Card > Game::playCard( bool &kingJustFound )
{
  shared_ptr<Card> playedCard; 

  if( currentTrick->getNumberOfCards() == players.size() )
    currentTrick->clearTrick();
  
  playedCard = next->playCard( currentTrick->getReferenceSuit(), currentTrick->getGreaterTrump() );
  currentTrick->setCard( next, playedCard );
  
  if( !kingFound )
    kingJustFound = isCardCalled( playedCard, next ) || kingJustFound;
	
  nextPlayer();

  return playedCard;
}

void Game::printScores() const
{
  for(shared_ptr<Player> player : players)
    cout << player->name << " " << player->score << endl;

  cout << "Takers: " << takers.getScore() << endl;
  cout << "Defenders: " << defenders.getScore() << endl;
}

bool Game::sameTeam( const shared_ptr<Player> p1, const shared_ptr<Player> p2 ) const
{
  return ( takers.contains(p1->name) && takers.contains(p2->name) ) 
    || ( defenders.contains(p1->name) && defenders.contains(p2->name) );
}

void Game::setGame( int& numberPlayers, const string yourName, const bool automatic )
{
  botsOnly = automatic;
  vector<string> names;
  names.push_back("Alice");
  names.push_back("Bob");
  
  if( numberPlayers == 3 )
  {
    dogSize = 6;
    cardsPerPlayer = 24;
    consecutiveDealing = 4;
    if( botsOnly )
      names.push_back("Charly");      
  }
  else if( numberPlayers == 5 )
  {
    dogSize = 3;
    cardsPerPlayer = 15;
    consecutiveDealing = 3;
    names.push_back("Charly");
    names.push_back("Dave");
    if( botsOnly )
      names.push_back("Erin");      
  }
  else
  {
    dogSize = 6;
    cardsPerPlayer = 18;
    consecutiveDealing = 3;
    names.push_back("Charly");
    if( botsOnly )
      names.push_back("Dave");      
    numberPlayers = 4;
  }
  
  if( !botsOnly )
    players.push_back( make_shared<Human>( yourName ) );

  players.push_back( make_shared<AI>( "Alice", names ) );
  players.push_back( make_shared<AI>( "Bob", names ) );

  if( numberPlayers >= 4 || botsOnly )
    players.push_back( make_shared<AI>( "Charly", names ) );
  if( numberPlayers == 5 || ( numberPlayers == 4 && botsOnly ) )
    players.push_back( make_shared<AI>( "Dave", names ) );
  if( numberPlayers == 5 && botsOnly )
    players.push_back( make_shared<AI>( "Erin", names ) );

  for( shared_ptr<Player> player : players )
    cardsPlayer[player->name].clear();
  
  indexNext = rand() % players.size();
  indexStarter = indexNext;
  next = players[ indexNext ];
}

void Game::showDeck() const
{
  cout << "Deck: ";
  for( shared_ptr<Card> card : deck.cards )
    cout << *card;
  cout << endl;
}

void Game::showPlayersCards() const
{
  for( shared_ptr<Player> player : players )
  {
    cout << player->name << ": ";
    player->showCards();
    cout << endl;
  }
}

void Game::shuffleDeck()
{
  for( unsigned int i = 0; i < players.size(); ++i )
    deck.shuffle();
}

pair< shared_ptr<Player>, Biddings > Game::takeBiddings( const Biddings &bestBid )
{
  if( indexToBid != -1 )
  {
    if( indexToBid == players.size() - 1 )
      indexToBid = 0;
    else
      ++indexToBid;
  }
  else
    indexToBid = rand() % players.size();
  
  pair< shared_ptr<Player>, Biddings > playerBid;
  
  Biddings bid = players[indexToBid]->bid( bestBid, chelemAnnounced );
  playerBid = make_pair( players[indexToBid], bid );
  
  if( players[indexToBid]->getAnnounced().find( Announcements::chelem ) != players[indexToBid]->getAnnounced().end() )
  {
    indexNext = indexToBid;
    next = players[indexToBid];
    chelemAnnounced = true;
  }
  
  return playerBid;
}

void Game::takeDog()
{
  if( bidding <= Biddings::guard )
  {
    for( shared_ptr<Card> card : dog )
    {
      players[indexBidder]->addCard( card );
      if( kingCalled == card )
      {
	defenders.members = unknown.members;
	unknown.members.clear();
	kingFound = true;
      }
    }

    dog.clear();
    addWonCards( players[indexBidder]->name, players[indexBidder]->makeEcart( dogSize ) );
  }
  else if( bidding == Biddings::guard_w )
  {
    addWonCards( players[indexBidder]->name, dog );
    dog.clear();
  }
  else
  {
    addDogAtTheEnd = true;
  }
}


//////////
// private

void Game::addWonCards( const string& name, const set<shared_ptr<Card> >& cards )
{
  cardsPlayer[name].insert(cards.begin(), cards.end());
}

bool Game::isCardCalled( const shared_ptr<Card> card, const shared_ptr<Player> player )
{
  if( kingCalled == card && !kingFound )
  {
    kingFound = true;
    takers.members[ player->name ] = player;
    unknown.members.erase( player->name );
    defenders.members = unknown.members;
  }
  
  return kingFound;
}

void Game::nextPlayer()
{
  if( indexNext == players.size() - 1 )
    indexNext = 0;
  else
    indexNext++;

  next = players[ indexNext ];
}

void Game::setNext( const shared_ptr<Player> player )
{
  next = player;
  for( unsigned int i = 0; i < players.size(); ++i )
    if( players[i] == player )
      indexNext = i;
}

void Game::swapFool()
{
  shared_ptr<Card> fromReceiver = nullptr;
  shared_ptr<Card> theFool;

  // search a dummy card
  for( shared_ptr<Card> card : cardsPlayer[foolReceiver->name] )
    if( card->getPoints() == 0.5 )
    {
      fromReceiver = card;
      break;
    }

  // search the Fool
  for( shared_ptr<Card> card : cardsPlayer[foolGiver->name] )
    if( card->isFool() )
    {
      theFool = card;
      break;
    }
  
  // swap if Receiver has something to swap
  if( fromReceiver )
  {
    cardsPlayer[foolReceiver->name].erase( fromReceiver );
    cardsPlayer[foolGiver->name].erase( theFool );
    
    cardsPlayer[foolReceiver->name].insert( theFool );
    cardsPlayer[foolGiver->name].insert( fromReceiver );
  }
}

void Game::update()
{
  addWonCards( currentTrick->getLeader()->name, currentTrick->getAllCards() );

  // if the Fool has been played, decide who must keep it.
  if( currentTrick->getFoolPlayer() != nullptr 
      && 
      !sameTeam(currentTrick->getFoolPlayer(), currentTrick->getLeader() ) )
  {
    toSwap = true;
    foolGiver = currentTrick->getLeader();
    foolReceiver = currentTrick->getFoolPlayer();
  }

  setNext( currentTrick->getLeader() );
  //currentTrick->getLeader()->score = currentTrick->getScore();
  history.push( currentTrick );
}
