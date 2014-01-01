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

#pragma once

#include <memory>
#include <map>
#include <vector>
#include <cstdlib>
#include <cassert>

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
    \param name A string for the AI name.
    \param knownPartners A vector of strings composed of the name of its partners.
  */
  AI( const string& name, const vector<string>& knownPartners);

  //! AI destructor.
  ~AI();

  //! To know if someone is your opponent.
  /*!
    \param name The Player's name in string.
    \return If the given Player is an opponent or not. 
  */
  bool isOpponent( const string& name ) const;

  //! To know if someone is your partner.
  /*!
    \param name The Player's name in string.
    \return If the given Player is an partner or not. 
  */
  bool isPartner( const string& name ) const;

  //! Given a Player p, does p have at least one card on the asked suit?
  /*!
    \param name The Player's name in string.
    \param suit The asked suit.
    \return False iff one is sure p does not have any cards of the asked suit.
  */
  bool haveSuit( const string& name, const Suits suit) const;

  //! Do opponents have at least one card on the asked suit?
  /*!
    \param suit The asked suit.
    \return False iff one is sure no opponent player has a card of the asked suit.
  */
  bool opponentsHaveSuit( const Suits suit ) const;

  //! Choose what card one plays, given the first card and the highest trump of the trick.
  /*!
    playCard is delegated to the difficulty Strategy.
    \param referenceCard A Card pointer of the first played card of the trick.
    \param highTrump A Card pointer of the highest trump of the trick.
    \return The card the AI plays.
  */
  shared_ptr<Card> playCard( shared_ptr<Card> referenceCard, shared_ptr<Card> highTrump);

  //! Must be called when starting a new game.
  /*!
    Flush to zero some variables and pointers.
  */
  void newGame();

  //! Called to decide if one proposes a bid or not, and if any, what bid.
  /*!
    bid is delegated to the difficulty Strategy.
    \param bestBid The best bid proposed so far.
    \param chelemAnnounced A Boolean to know if someone has declared a chelem.
    \return Our bid (Biddings::none if one passes).
  */
  Biddings bid( const Biddings bestBid, const bool chelemAnnounced) const;

  //! To make the ecart once one takes the dog.
  /*!
    makeEcart is delegated to the difficulty Strategy.
    \param dogSize The number of card one must include into the ecart.
    \return A set of Card pointers for the cards one places into the ecart.
  */
  set< shared_ptr<Card> > makeEcart( const int dogSize );

  //! Inline function to set the difficulty (set a Strategy concrete class).
  /*!
    \param diff A pointer on the difficuty to set.
  */
  inline void setDifficulty ( shared_ptr<StratDiff> diff ) {difficulty = diff;}

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
      \param suit The asked suit.
      \return True iif there remains at least one card of the given suit in the hand of other players.
    */
    bool hasSuit( const Suits suit ) const
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

  Deck			cardCounting;	//!< A deck to count cards.
  map<string, Counting>	opponents;	//!< To remember what remains among opponents' hands. 
  map<string, Counting>	partners;	//!< To remember what remains among partners' hands.
  shared_ptr<StratDiff>	difficulty;	//!< A pointer on the current difficulty.
};
