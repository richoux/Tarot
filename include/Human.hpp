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
#include <vector>

#include <Player.hpp>
#include <Suits.hpp>
#include <Card.hpp>
#include <getInt.hpp>
#include <getChar.hpp>

using namespace std;

//! Human is the class implementing Human player actions, like playing a card.
class Human : public Player
{
public:
  //! The unique constructor of Human.
  /*!
    \param name The name of the Human player.
  */
  Human( string name );

  //! The unique destructor of Human.
  ~Human();
  
  //! To play a card, knowing the ask suit and the highest trump of the trick, if any.
  /*!
    \param referenceCard The card fixing the ask suit for the trick.
    \param highTrump The highest trump played so far for the trick, if any.
    \return The card the player plays.
  */
  shared_ptr<Card> playCard( shared_ptr<Card> referenceCard, shared_ptr<Card> highTrump );

  //! To get prepared for a new game.
  void newGame();
  
  //! To let the Human player bids.
  /*!
    \param bestBid The best bid proposed so far. 
    \param chelemAnnounced True iff a chelem has been announced.
    \return The Human player's bid.
  */
  Biddings bid( Biddings bestBid, bool chelemAnnounced );
  
  //! To let the Human player makes his/her ecart.
  /*!
    \param dogSize The number of cards to put into the ecart.
  */
  set< shared_ptr<Card> > makeEcart( int dogSize );
};
