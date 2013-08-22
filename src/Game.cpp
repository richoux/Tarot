/*
* Tarot is an application for Android system to play to French Tarot.
* Please visit https://github.com/richoux/Tarot for further information.
* 
* Copyright (C) 2013 Florian Richoux
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

#include <Game.hpp>

Game::Game( int numberPlayers, string yourName )
{
  vector<string> names;
  names.push_back("Alice");
  names.push_back("Bob");

  if( numberPlayers == 3 )
    {
      dogSize = 6;
      cardsPerPlayer = 24;
      consecutiveDealing = 4;
    }
  else if( numberPlayers == 5 )
    {
      dogSize = 3;
      cardsPerPlayer = 15;
      consecutiveDealing = 3;
      names.push_back("Charly");
      names.push_back("Dave");
    }
  else
    {
      dogSize = 6;
      cardsPerPlayer = 18;
      consecutiveDealing = 3;
      names.push_back("Charly");
      numberPlayers = 4;
    }

  players.push_back( shared_ptr<Human>( new Human( yourName ) ) );
  players.push_back( shared_ptr<AI>( new AI( "Alice", names ) ) );
  players.push_back( shared_ptr<AI>( new AI( "Bob", names ) ) );
  
  if( numberPlayers >= 4)
    {

      players.push_back( shared_ptr<AI>( new AI( "Charly", names ) ) );
      if( numberPlayers == 5)
	players.push_back( shared_ptr<AI>( new AI( "Dave", names ) ) );
    }

  indexPlayers = rand() % players.size();
  next = players[ indexPlayers ];
  foolGiver = foolReceiver = nullptr;
  toSwap = false;
}

Game::~Game()
{
  players.clear();

  while( !history.empty() )
    history.pop();
}

void Game::newGame()
{
  for( shared_ptr<Player> player : players )
    player->newGame();

  while( !history.empty() )
    history.pop();

  takers.newGame();
  defenders.newGame();
  if( players.size() == 5 )
    unknown.newGame();

  foolGiver = foolReceiver = nullptr;
  toSwap = false;
}

void Game::printScores()
{
  for(shared_ptr<Player> player : players)
    cout << player->name << " " << player->score << endl;
}

void Game::showDeck()
{
  cout << "Deck: ";
  for( shared_ptr<Card> card : deck.cards )
    cout << *card;
  cout << endl;
}

void Game::showPlayersCards()
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
  for( int i = 0; i < players.size(); ++i )
    deck.shuffle();
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

  // deal cards to players and the dog
  for( int round = 0; round < cardsPerPlayer; round += consecutiveDealing )
    for( int gamers = 0; gamers < players.size(); gamers++ )
      {
	for( int card = 0; card < consecutiveDealing; card++ )
	  {
	    // card for the dog
	    if( indexDog.find( indexCard ) != indexDog.end() )
	      {
		dog.insert( deck.cards[ indexCard++ ] );
		card--;
	      }
	    // card for a player
	    else
	      next->addCard( deck.cards[ indexCard++ ] );
	  }
	nextPlayer();
      }
  
  cout << "Dog: ";
  for( shared_ptr<Card> card : dog )
    cout << *card;
  cout << endl;
}

void Game::nextPlayer()
{
  if( indexPlayers == players.size() - 1 )
    indexPlayers = 0;
  else
    indexPlayers++;

  next = players[ indexPlayers ];
}

void Game::setNext( shared_ptr<Player> player )
{
  next = player;
  for( int i = 0; i < players.size(); ++i )
    if( players[i] == player )
      indexPlayers = i;
}

bool Game::sameTeam( shared_ptr<Player> p1, shared_ptr<Player> p2 )
{
  return ( takers.contains(p1->name) && takers.contains(p2->name) ) 
    || ( defenders.contains(p1->name) && defenders.contains(p2->name) );
}

Team Game::play()
{
  shared_ptr<Card> refCard; 
  dealCards();

  takers.members[next->name] = next;
  cout << "Taker: " << takers << endl;

  for( int gamer = 1; gamer < players.size(); ++gamer )
    {
      nextPlayer();
      defenders.members[next->name] = next;
    }
  cout << "Defenders: " << defenders << endl;
  nextPlayer();

  for( int round = 0; round < cardsPerPlayer; ++round )
    {
      cout << endl;
      cout << "**************" << endl;
      cout << "** Round " << round+1 << " **" << endl;
      cout << "**************" << endl;

      currentTrick = shared_ptr<Trick>( new Trick( nullptr ) );
      
      for( int gamer = 0; gamer < players.size(); ++gamer )
	{
	  if( gamer == 0)
	    {
	      refCard = next->playCard( nullptr, nullptr );
	      currentTrick->setCard( next, refCard );
	    }
	  else if( gamer == 1 && refCard->isFool() )
	    {
	      refCard = next->playCard( refCard, nullptr );
	      currentTrick->setCard( next, refCard );
	    }
	  else
	    currentTrick->setCard( next, 
				   next->playCard( refCard, 
						   currentTrick->getGreaterTrump() ) );
	  
	  nextPlayer();
	}
      
      cout << "Trick: ";
      currentTrick->showAllCards();
      cout << ". Won by " << currentTrick->getLeader()->name << endl;

      addWinnedCards( currentTrick->getLeader()->name, currentTrick->getAllCards() );

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

  if( toSwap )
    swapFool();

  cout << "Winned cards:" << endl;
  for( auto player : players )
    {
      cout << player->name << ": ";
      for( auto card : cardsPlayer[player->name])
	cout << *card << " ";
      cout << endl;
    }

  // Compute score for each player
  for( shared_ptr<Player> player : players )
    player->score = computeScore( player->name );

  if( takers > defenders )
    return takers;
  else
    return defenders;
}

void Game::addWinnedCards( string name, set<shared_ptr<Card> > cards )
{
  cardsPlayer[name].insert(cards.begin(), cards.end());
}

double Game::computeScore( string name)
{
  double score = 0;
  
  for( shared_ptr<Card> card : cardsPlayer[name] )
    score += card->getPoints();

  return score;
}

void Game::swapFool()
{
  shared_ptr<Card> fromReceiver;
  shared_ptr<Card> theFool;

  // for( auto player : players )
  //   {
  //     cout << player->name << ": ";
  //     for( auto card : cardsPlayer[player->name])
  // 	cout << *card << " ";
  //     cout << endl;
  //   }

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
  
  // swap
  cardsPlayer[foolReceiver->name].erase( fromReceiver );
  cardsPlayer[foolGiver->name].erase( theFool );
  
  cardsPlayer[foolReceiver->name].insert( theFool );
  cardsPlayer[foolGiver->name].insert( fromReceiver );
}
