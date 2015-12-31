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

#include <Beginner.hpp>

shared_ptr<Card> Beginner::playCard( const vector< shared_ptr<Card> >& cardsCanPlay ) const
{
  assert( !cardsCanPlay.empty() );
  // play random
  return cardsCanPlay[ rand() % cardsCanPlay.size() ]; 
}

Biddings Beginner::bid( const Biddings bestBid, const int numberOudlers, const bool chelemAnnounced ) const
{
  int chance = rand() % 101;

  if( numberOudlers == 0 )
  {
    if( bestBid == Biddings::none && chance >= 50 )
      return Biddings::small;
    else
      return Biddings::none;
  }
  else if( numberOudlers == 1 )
  {
    if( bestBid <= Biddings::small && chance >= 80 )
      return Biddings::guard;
    else if( bestBid == Biddings::none && chance >= 35 )
      return Biddings::small;
    else
      return Biddings::none;
  }
  else if( numberOudlers == 2 )
  {
    if( bestBid <= Biddings::guard && chance >= 90 )
      return Biddings::guard_w;
    else if( bestBid <= Biddings::small && chance >= 65 )
      return Biddings::guard;
    else if( bestBid == Biddings::none && chance >= 20 )
      return Biddings::small;
    else
      return Biddings::none;
  }
  else
  {
    if( bestBid <= Biddings::guard_w && chance >= 95 )
      return Biddings::guard_a;
    else if( bestBid <= Biddings::guard && chance >= 80 )
      return Biddings::guard_w;
    else if( bestBid <= Biddings::small && chance >= 40 )
      return Biddings::guard;
    else if( bestBid == Biddings::none && chance >= 10 )
      return Biddings::small;
    else
      return Biddings::none;
  }
}

set< shared_ptr<Card> >	Beginner::makeEcart( const int dogSize, const vector< shared_ptr<Card> >& allCards ) const
{
#if defined DEBUG
  if( ! (allCards.size() >= 18 && allCards.size() <= 30) )
  {
    cout << "Card size: " << allCards.size() << endl;
    for( int i = 0 ; i < allCards.size() ; ++i )
      cout << *allCards[i] << " ";
    cout << endl;
  }
#endif
  assert( allCards.size() >= 18 && allCards.size() <= 30 );

  set< shared_ptr<Card> > ecart;
  
  while( ecart.size() < dogSize )
    ecart.insert( allCards[rand() % allCards.size()]);
  
  return ecart;
}
