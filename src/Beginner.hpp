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
#include <set>
#include <memory>

#include "Biddings.hpp"
#include "Card.hpp"
#include "StratDiff.hpp"

using namespace std;

//! One of the proposed difficulty.
/*! 
  Beginner is one of the concrete class of the Strategy pattern dealing with 
  the game difficulty (i.e., how good the AI is). 
*/
class Beginner : public StratDiff
{
public:
  //! Called to decide if we propose a bid or not, and if any, what bid.
  /*!
    bid is delegated to the difficulty Strategy.
    \param bestBid The best bid proposed so far.
    \param numberOudlers The number of oudlers we have in our hand.
    \param chelemAnnounced A Boolean to know if someone has declared a chelem.
    \return Our bid (Biddings::none if we pass).
  */
  Biddings bid( const Biddings bestBid, const int numberOudlers, const bool chelemAnnounced) const;

  //! To make the ecart once we take the dog.
  /*!
    makeEcart is delegated to the difficulty Strategy.
    \param dogSize The number of card we must include into the ecart.
    \param allCards The vector of all our cards, including the dog.
    \return A set of Card pointers for the cards we place into the ecart.
  */
  set< shared_ptr<Card> > makeEcart( const int dogSize, const vector< shared_ptr<Card> >& allCards) const;
  
  //! Choose what card we play, given the first card and the highest trump of the trick.
  /*!
    \param cardCanPlay The vector of cards one is allowed to play.
    \return The card we play.
  */
  shared_ptr<Card> playCard( const vector< shared_ptr<Card> >& cardsCanPlay) const;
};
