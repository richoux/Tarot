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

Game::Game( int numberPlayers )
{
  players.insert( new Human( "You" ) );
  players.insert( new AI( "Alice" ) );
  players.insert( new AI( "Bob" ) );
  
  if( numberPlayers >= 4)
    {
      players.insert( new AI( "Charly" ) );
      if( numberPlayers == 5)
	players.insert( new AI( "Dave" ) );
    }

  currentTrick	= nullptr;
  nextPlayer	= nullptr;
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
    player.newGame();

  while( !history.empty() )
    history.pop();

  takers.newGame();
  defenders.newGame();
  if( players.size() == 5 )
    unknown.newGame();
}

void Game::printScores()
{
  cout << 
}

Team Game::play()
{

}
