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
#include <cstdlib>

#include <Player.hpp>
#include <Suits.hpp>
#include <Card.hpp>
#include <Deck.hpp>
#include <StratDiff.hpp>
#include <Beginner.hpp>
#include <Biddings.hpp>

using namespace std;

//! This class defines AI players
/*!
  The class AI extends Player and shows an interface for actions like playCard, make a bid, etc.
  Actions' implementation is decoupled from the class with a Strategy pattern, where concret classes
  correspond to a level of difficulty.
 */
class AI : public Player
{
public:
  //! AI constructor
  /*!
    This is the unique constructor for AI.
    \param a string for the AI name
    \param a vector of strings composed of the name of its partners.
   */
  AI( string, vector<string> );

  //! AI destructor
  /*!
    This is the unique destructor for AI. It does nothing special.
   */
  ~AI();

  bool				isOpponent		( string );
  bool				isPartner		( string );
  bool				haveSuit		( string, Suits );
  bool				opponentsHaveSuit	( Suits );
  shared_ptr<Card>		playCard		( shared_ptr<Card>, shared_ptr<Card> );
  void				newGame			();
  Biddings			bid			( Biddings, bool );
  set< shared_ptr<Card> >	makeEcart		( int );

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
    
    bool hasSuit( Suits suit ) const
    {
      switch( suit )
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
