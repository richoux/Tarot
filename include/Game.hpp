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

#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <memory>
#include <cstdlib>

#include <Colors.hpp>
#include <Biddings.hpp>
#include <Team.hpp>
#include <Player.hpp>
#include <Human.hpp>
#include <AI.hpp>
// #include <StratLang.hpp>
#include <Trick.hpp>
#include <Deck.hpp>

using namespace std; 

class Game
{
public:
  Game( int, string = "You" );
  ~Game();

  void newGame();
  void printScores();
  Team play();
  void showDeck();
  void showPlayersCards();
  void shuffleDeck();
  void dealCards();
  void nextPlayer();

private:
  vector< shared_ptr<Player> >	players;
  // shared_ptr<StratLang>		language;
  shared_ptr<Trick>		currentTrick;
  stack< shared_ptr<Trick> >	history;
  shared_ptr<Player>		next;
  int				indexPlayers;
  Deck				deck;
  set< shared_ptr<Card> >	dog;
  Team				takers;
  Team				defenders;
  Team				unknown;
  Biddings			bidding;
  Colors			kingCalled;
  int				dogSize;
  int				cardsPerPlayer;
  int				consecutiveDealing;
};
