/*
 * Tarot is an application for Android system to play to French Tarot.
 * Please visit https://github.com/richoux/Tarot for further information.
 * 
 * Copyright (C) 2013-2014 Florian Richoux
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
#include <cstring>

#include <Game.hpp>
#include <getInt.hpp>

using namespace std;

int main( int argc, char **argv )
{
  srand ( unsigned ( time(0) ) );

  Game *game;
  string playerName;
  int nberPlayers;

  if( argc >= 2 && strcmp( argv[1], "--auto") == 0 )
  {
    nberPlayers = 4;
    game = new Game( nberPlayers, playerName, true );

    game->shuffleDeck();
    game->showDeck();
    game->showPlayersCards();
  }
  else if( argc == 1 )
  {
    cout << "Please enter your name." << endl;
    getline( cin, playerName );
    nberPlayers = getInt( "Please enter the number of players.\n" );

    if( playerName.compare("") != 0 )
      game = new Game( nberPlayers, playerName );
    else
      game = new Game( nberPlayers );

    game->shuffleDeck();
  }

  if( argc >= 3 && strcmp( argv[1], "--auto") == 0 && strcmp( argv[2], "--debug") == 0 )
  {
    for( int i = 0 ; i < 1000 ; ++i )
    {
      cout << "***********" << endl;
      cout << "*** " << i << " ***" << endl;
      cout << "***********" << endl;

      Team winners = game->play();
  
      game->printScores();  
      cout << "Winners: " << winners << endl;

      game->newGame();
    }
  }
  else
  {
    Team winners = game->play();
    
    game->printScores();  
    cout << "Winners: " << winners << endl;
  }
  delete game;
}
