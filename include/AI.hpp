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

#include <memory>
#include <map>
#include <vector>

#include <Player.hpp>
#include <Colors.hpp>
#include <Card.hpp>
#include <Deck.hpp>
#include <StratDiff.hpp>
#include <Beginner.hpp>

using namespace std;

class AI : public Player
{
public:
  AI( string, vector<string> );
  ~AI();

  bool			isOpponent		( string );
  bool			isPartner		( string );
  bool			haveColor		( string, Colors );
  bool			opponentsHaveColor	( Colors );
  shared_ptr<Card>	playCard		( shared_ptr<Card>, shared_ptr<Card> );
  void			newGame			();

  inline void setDifficulty ( shared_ptr<StratDiff> diff) {difficulty = diff;}

private:
  class Counting
  {
  public:
    Counting()
      : hasHeart(true),
	hasSpade(true),
	hasDiamond(true),
	hasClub(true),
	hasTrump(true) {}
    
    bool hasHeart;
    bool hasSpade;
    bool hasDiamond;
    bool hasClub;
    bool hasTrump;
    
    bool hasColor( Colors color ) const
    {
      switch( color )
	{
	case heart:
	  return hasHeart;
	case spade:
	  return hasSpade;
	case diamond:
	  return hasDiamond;
	case club:
	  return hasClub;
	case trump:
	  return hasTrump;
	default:
	  return true;
	}
    }
  };

  Deck			cardCounting;
  map<string, Counting>	opponents;
  map<string, Counting>	partners;
  shared_ptr<StratDiff>	difficulty;
};
