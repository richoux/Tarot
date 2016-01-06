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

#pragma once

#include <map>
#include <set>
#include <memory>

#include "Player.hpp"
#include "Card.hpp"

using namespace std;

//! This class manages the current and previously played tricks.
class Trick
{
public:
  //! The unique constructor of Trick.
  Trick();

  //! Get all cards in the current trick.
  set< shared_ptr<Card> > getAllCards() const;

  //! Update the trickCards map, and determine also the value of other variables like foolPlayer, greaterTrump and leader.
  /*!
    \param player A pointer on the player who just played.
    \param card A point on the card the player just played.
  */
  void setCard( const shared_ptr<Player> player, const shared_ptr<Card> card );

  //! To get the cumulative points of the current trick.
  double getScore() const;

  //! Inline function returning the number of cards composing the trick.
  inline int getNumberOfCards() const { return trickCards.empty() ? 0 : trickCards.size(); }

  //! Show all card of the current trick
  void showAllCards() const;

  //! Clear trick data (cards, leader, ...).
  void clearTrick();

  //! Inline assessor to the card played of the given player during the current trick.
  inline shared_ptr<Card>	getCard		( const shared_ptr<Player> player )	const { return trickCards.at(player); }

  //! Inline function returning the card which takes the trick.
  inline shared_ptr<Card>	getWinCard	()				const { return trickCards.at(leader); }

  // Inline assessor to get the pointer on the leader.
  inline shared_ptr<Player>	getLeader	()				const { return leader; }

  // Inline assessor to get the pointer on the player who played the Fool.
  inline shared_ptr<Player>	getFoolPlayer	()				const { return foolPlayer; }

  // Inline assessor to get the pointer on the greatest trump of the current trick.
  inline shared_ptr<Card>	getGreaterTrump	()				const { return greaterTrump; }

  // Inline assessor to get the pointer on the greatest trump of the current trick.
  inline Suits			getReferenceSuit()				const { return referenceSuit; }

private:
  shared_ptr<Player>				leader;		//!< A pointer on the actual leader (i.e., current winner) of the trick.
  shared_ptr<Player>				foolPlayer;	//!< A pointer on the player who played the Fool.
  shared_ptr<Card>				greaterTrump;	//!< A pointer on the greatest trump played so far in the trick.
  Suits						referenceSuit;	//!< The suit of the first card played (second if the fool has been played first).
  map< shared_ptr<Player>, shared_ptr<Card> >	trickCards;	//!< A map of all cards composing the trick.
};
