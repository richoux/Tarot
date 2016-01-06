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

#include <vector>
#include <memory>

#include "Card.hpp"

using namespace std;

//! Deck is the class managing the deck of cards. Used as well as for the game deck, but also for a counting cards AI.
class Deck
{
public:
  //! The unique constructor of Deck.
  Deck();

  //! Tests if the current deck has a stronger card than to proposed one.
  /*!
    \param card A pointer of Card.
    \return True iff the deck has a stronger card than the input. 
  */
  bool hasStrongerThan( const shared_ptr<Card> card ) const;

  //! indexInDeck returns the index of a card in the deck.
  /*!
    \param card A pointer of Card.
    \return The index of card in the Deck, or -1 if the deck does not contain it.
  */
  int indexInDeck( const shared_ptr<Card> card ) const;

  //! Make a new deal; create each card of the game.
  void newDeal();

  //! Calls random_shuffle from the algorithm library.
  void shuffle();

  vector< shared_ptr<Card> >	cards;		//!< The vector of all cards in the deck.
  vector< shared_ptr<Card> >	heads;		//!< The vector of head cards (useful calling a card for 5-players games).  
  int				numberHearts;	//!< The number of Hearts in the deck.
  int				numberSpades;	//!< The number of Spades in the deck.	
  int				numberDiamonds;	//!< The number of Diamonds in the deck.
  int				numberClubs;	//!< The number of Clubs in the deck.
  int				numberTrumps;	//!< The number of Trumps in the deck.
};
