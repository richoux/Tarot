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

#include <map>
#include <set>
#include <memory>
#include <iostream>

#include <Player.hpp>
#include <Card.hpp>

using namespace std;

//! This class manages the current and previously played tricks.
class Trick
{
public:
  Trick( shared_ptr<Card> );
  ~Trick();
  
  shared_ptr<Player> asCalledKing();
  set< shared_ptr<Card> > getAllCards();
  void setCard( shared_ptr<Player>, shared_ptr<Card> );
  double getScore();
  void showAllCards();

  inline shared_ptr<Card>	getCard		( shared_ptr<Player> player ) { return trickCards[player]; }
  inline shared_ptr<Card>	getWinCard	() { return trickCards[leader]; }
  inline shared_ptr<Player>	getLeader	() { return leader; }
  inline shared_ptr<Player>	getFoolPlayer	() { return foolPlayer; }
  inline shared_ptr<Card>	getGreaterTrump	() { return greaterTrump; }

private:
  shared_ptr<Player>				leader;		//!< A pointer on the actual leader (i.e., current winner) of the trick.
  shared_ptr<Player>				foolPlayer;	//!< A pointer on the player who played the Fool.
  shared_ptr<Card>				kingCalled;	//!< A pointer on the king (or others) card asked at the beginning of a 5-player game.
  shared_ptr<Card>				greaterTrump;	//!< A pointer on the greatest trump played so far in the trick.
  map< shared_ptr<Player>, shared_ptr<Card> >	trickCards;	//!< A map of all cards composing the trick.
};
