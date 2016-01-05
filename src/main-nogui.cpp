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
#include <string>

#include <Game.hpp>
#include <getInt.hpp>

using namespace std;

void usage()
{
  cout << "tarot [--debug [ #players [ #games ] ] ]" << endl;
}

void printRound( string toPrint )
{
  string stars;
  for( int i = 0 ; i < toPrint.size(); ++i )
    stars += "*";
  
  cout << endl
       << "****" << stars << "****" << endl
       << "*** " << toPrint << " ***" << endl
       << "****" << stars << "****" << endl;
}

void gameLoop( Game &game )
{
  game.dealCards();
  
  if( game.isBotsOnly() )
    game.showPlayersCards();

  bool allPassed = true;
  Biddings bestBid = Biddings::none;  
  for( int p = 0 ; p < game.getNumberPlayers() ; ++p )
  {
    auto bid = game.takeBiddings( bestBid );
    if( bid.second == Biddings::none )
      cout << bid.first->name << " passes." << endl;
    else
    {
      allPassed = false;
      if( bestBid < bid.second )
      {
	game.updateIndexBidder();
	bestBid = bid.second;
      }
      
      cout << bid.first->name << " takes a ";
      switch( bid.second )
      {
      case Biddings::small:
	cout << "Small." << endl;
	break;
      case Biddings::guard:
	cout << "Guard." << endl;
	break;
      case Biddings::guard_w:
	cout << "Guard Without." << endl;
	break;
      case Biddings::guard_a:
	cout << "Guard Against." << endl;
	break;
      default:
	break;
      }
    }
  }
    
  if( allPassed )
  {
    cout << "All players passed." << endl;
    return;
  }

  game.closeBiddings();
  
  if( game.getNumberPlayers() == 5 )
  {
    game.chooseKing();
    cout << game.getTakers().members.begin()->first << " called " << *game.getKingCalled() << endl;
  }
  
  if( game.getBidding() <= Biddings::guard )
  {
    cout << "Show dog: ";
    for( shared_ptr<Card> card : game.getDog() )
      cout << *card << " ";
    cout << endl;
  }
  
  game.takeDog();
  if( game.isKingFound() && game.isBotsOnly() )
  {
    cout << "Player alone! Unlucky!" << endl
	 << "Taker: " << game.getTakers() << endl
	 << "Defenders: " << game.getDefenders() << endl;      
  }
  
  cout << "Taker: " << game.getTakers() << endl;
  if( game.getNumberPlayers() <= 5 )
    cout << "Defenders: " << game.getDefenders() << endl;

  if( game.isBotsOnly() )
    game.showPlayersCards();

  bool kingJustFound;
  
  for( int round = 0; round < game.getCardsPerPlayer(); ++round )
  {
    string roundString("Round ");
    roundString += to_string( round + 1 );
    printRound( roundString );

    auto trick = game.playTrick( kingJustFound );
    cout << "Trick: ";
    trick->showAllCards();
    cout << "=> Won by " << trick->getLeader()->name << endl;

    if( kingJustFound && game.isBotsOnly() )
    {
      cout << "Parter known!" << endl
	   << "Taker: " << game.getTakers() << endl
	   << "Defenders: " << game.getDefenders() << endl;      
    }

  }

  Team winners = game.endGame();

  cout << "Won cards:" << endl;
  for( auto player : game.getPlayers() )
  {
    cout << player->name << ": ";
    for( auto card : game.getPlayerWonCards( player ) )
      cout << *card << " ";
    cout << endl;
  }

  if( !winners.isEmpty() )
  {
    game.printScores();  
    cout << "Winners: " << winners << endl;
  }
}

int main( int argc, char **argv )
{
  srand ( unsigned ( time(0) ) );

  Game game;
  string playerName;
  int nberPlayers;
  int loop = 1;

  if( argc >= 2 )
  {
    string arg( argv[1] );
    if( arg.compare( "--debug" ) != 0 || argc > 4 )
    {
      usage();
      exit(1);
    }
    
    if( argc == 2 )
      nberPlayers = 4;
    else if( argc == 3 )
      nberPlayers = atoi( argv[2] );
    else
    {
      nberPlayers = atoi( argv[2] );
      loop = atoi( argv[3] );
    }

    game.setGame( nberPlayers, playerName, true );

    game.shuffleDeck();
    game.showDeck();
    game.showPlayersCards();
  }
  else
  {
    cout << "Please enter your name." << endl;
    getline( cin, playerName );
    do {
      nberPlayers = getInt( "Please enter the number of players: 3, 4 or 5.\n" );
    } while( nberPlayers < 3 || nberPlayers > 5 );
    
    if( !playerName.empty() )
      game.setGame( nberPlayers, playerName );
    else
      game.setGame( nberPlayers );

    game.shuffleDeck();
  }

  if( game.isBotsOnly() )
  {
    for( int i = 0 ; i < loop ; ++i )
    {
      string numberGames( to_string( i ) );
      printRound( numberGames );
      
      gameLoop( game );
      game.newGame();
    }
  }
  else
    gameLoop( game );
}
