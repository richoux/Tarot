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

#include <iostream>
#include <cstdlib>

#include <Game.hpp>
#include <getInt.hpp>

using namespace std;

int main(int argc, char **argv)
{
  srand ( unsigned ( time(0) ) );

  Game *game;
  string playerName;
  int nberPlayers;

  cout << "Please enter your name." << endl;
  getline( cin, playerName );
 
  nberPlayers = getInt( "Please enter the number of players.\n" );

  if( playerName.compare("") != 0 )
    game = new Game( nberPlayers, playerName );
  else
    game = new Game( nberPlayers );

  //game->printScores();
  //game->showDeck();
  //game->shuffleDeck();
  //game->showDeck();
  //game->dealCards();
  //game->showPlayersCards();
  Team winners = game->play();
  
  cout << "Winners: " << winners;

  delete game;
}
