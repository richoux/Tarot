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

//! This class defines AI players.
/*!
  The class AI extends Player and shows an interface for actions like playCard, make a bid, etc.
  Actions' implementation is decoupled from the class with a Strategy pattern, where concret classes
  correspond to a level of difficulty.
 */
class AI : public Player
{
public:
  //! AI constructor.
  /*!
    This is the unique constructor for AI.
    \param a string for the AI name.
    \param a vector of strings composed of the name of its partners.
  */
  AI( string, vector<string> );

  //! AI destructor.
  /*!
    This is the unique destructor for AI. It does nothing special.
  */
  ~AI();

  //! To know if someone is your opponent.
  /*!
    \param The Player's name in string.
    \return If the given Player is an opponent or not. 
  */
  bool				isOpponent		( string );

  //! To know if someone is your partner.
  /*!
    \param The Player's name in string.
    \return If the given Player is an partner or not. 
  */
  bool				isPartner		( string );

  //! Given a Player p, does p have at least one card on the asked suit?
  /*!
    \param The Player's name in string.
    \param The asked suit.
    \return False iff we are sure p does not have any cards of the asked suit.
  */
  bool				haveSuit		( string, Suits );

  //! Do opponents have at least one card on the asked suit?
  /*!
    \param The asked suit.
    \return False iff we are sure no opponent player has a card of the asked suit.
  */
  bool				opponentsHaveSuit	( Suits );

  //! Choose what card we play, given the first card and the highest trump of the trick.
  /*!
    playCard is delegated to the difficulty Strategy.
    \param A Card pointer of the first played card of the trick.
    \param A Card pointer of the highest trump of the trick.
    \return The card we play.
  */
  shared_ptr<Card>		playCard		( shared_ptr<Card>, shared_ptr<Card> );

  //! Must be called when starting a new game.
  /*!
    Flush to zero some variables and pointers.
  */
  void				newGame			();

  //! Called to decide if we propose a bid or not, and if any, what bid.
  /*!
    bid is delegated to the difficulty Strategy.
    \param The best bid proposed so far.
    \param A Boolean to know if someone has declared a chelem.
    \return Our bid (Biddings::none if we pass)
  */
  Biddings			bid			( Biddings, bool );

  //! To make the ecart once we take the dog.
  /*!
    makeEcart is delegated to the difficulty Strategy.
    \param The number of card we must include into the ecart.
    \return A set of Card pointers for the cards we place into the ecart.
  */
  set< shared_ptr<Card> >	makeEcart		( int );

  //! Inline function to set the difficulty (set a Strategy concrete class)
  /*!
    \param A pointer on the difficuty to set.
  */
  inline void setDifficulty ( shared_ptr<StratDiff> diff) {difficulty = diff;}

private:

  //! Inner class for counting cards.
  class Counting
  {
  public:
    //! Counting constructor, setting each Boolean variable to true.
    Counting()
      : hasHeart(true),
	hasSpade(true),
	hasDiamond(true),
	hasClub(true),
	hasTrump(true) {}
    
    bool hasHeart;	//!< True iff there remains at least one Heart card in the hand of other players.
    bool hasSpade;	//!< True iff there remains at least one Spade card in the hand of other players.
    bool hasDiamond;	//!< True iff there remains at least one Diamond card in the hand of other players.
    bool hasClub;	//!< True iff there remains at least one Club card in the hand of other players.
    bool hasTrump;	//!< True iff there remains at least one trump in the hand of other players.
    
    //! To know if there remains at least one card of the given suit in the hand of other players.
    /*!
      \param The asked suit.
      \return True iif there remains at least one card of the given suit in the hand of other players.
     */
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

  Deck			cardCounting;	//!< A deck to count cards
  map<string, Counting>	opponents;	//!< To remember what remains among opponents' hands. 
  map<string, Counting>	partners;	//!< To remember what remains among partners' hands.
  shared_ptr<StratDiff>	difficulty;	//!< A pointer on the current difficulty.
};
