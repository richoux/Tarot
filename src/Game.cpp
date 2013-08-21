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

  switch( numberPlayers )
    {
    case 3:
      dogSize = 6;
      cardsPerPlayer = 24;
      consecutiveDealing = 4;
      break;
    case 5:
      dogSize = 3;
      cardsPerPlayer = 15;
      consecutiveDealing = 3;
      names.push_back("Charly");
      names.push_back("Dave");
      break;
    default:
      dogSize = 6;
      cardsPerPlayer = 18;
      consecutiveDealing = 3;
      names.push_back("Charly");
      break;
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

  currentTrick = nullptr;
  indexPlayers = rand() % players.size();
  next = players[ indexPlayers ];
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
  deck.shuffle();
  deck.shuffle();
  deck.shuffle();
  cout << "Deck shuffled!" << endl;
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

Team Game::play()
{
  dealCards();
  return Team();
}
