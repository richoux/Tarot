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

#include <algorithm>
#include <random>
#include <iterator>
#include <ctime>
#include <chrono>

#include "Deck.hpp"

Deck::Deck()
{
  newDeal();
}

bool Deck::hasStrongerThan( const shared_ptr<Card> card ) const
{
  for( auto it = cards.cbegin(); it != cards.cend(); ++it )
    if( *(*it) > *card)
      return true;

  return false;  
}

int Deck::indexInDeck( const shared_ptr<Card> card ) const
{
  auto index = find( cards.cbegin(), cards.cend(), card );
  if( index == cards.cend() )
    return -1;
  else
    return distance( cards.cbegin(), index );
}

void Deck::newDeal()
{
  if( _seed == 0 )
    _seed = chrono::system_clock::now().time_since_epoch().count();
  
  cards.clear();
  heads.clear();
  
  // Hearts
  cards.push_back( make_shared<Card>( Suits::heart, 1, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 2, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 3, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 4, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 5, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 6, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 7, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 8, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 9, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 10, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 11, 1.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 12, 2.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 13, 3.5, false ) );
  cards.push_back( make_shared<Card>( Suits::heart, 14, 4.5, false ) );

  // Spades
  cards.push_back( make_shared<Card>( Suits::spade, 1, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 2, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 3, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 4, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 5, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 6, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 7, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 8, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 9, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 10, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 11, 1.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 12, 2.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 13, 3.5, false ) );
  cards.push_back( make_shared<Card>( Suits::spade, 14, 4.5, false ) );

  // Diamonds
  cards.push_back( make_shared<Card>( Suits::diamond, 1, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 2, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 3, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 4, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 5, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 6, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 7, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 8, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 9, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 10, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 11, 1.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 12, 2.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 13, 3.5, false ) );
  cards.push_back( make_shared<Card>( Suits::diamond, 14, 4.5, false ) );

  // Clubs
  cards.push_back( make_shared<Card>( Suits::club, 1, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 2, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 3, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 4, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 5, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 6, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 7, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 8, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 9, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 10, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 11, 1.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 12, 2.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 13, 3.5, false ) );
  cards.push_back( make_shared<Card>( Suits::club, 14, 4.5, false ) );

  // Trumps
  cards.push_back( make_shared<Card>( Suits::trump, 1, 4.5, true ) );
  cards.push_back( make_shared<Card>( Suits::trump, 2, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 3, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 4, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 5, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 6, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 7, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 8, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 9, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 10, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 11, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 12, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 13, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 14, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 15, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 16, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 17, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 18, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 19, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 20, 0.5, false ) );
  cards.push_back( make_shared<Card>( Suits::trump, 21, 4.5, true ) );

  // Fool
  cards.push_back( make_shared<Card>( Suits::fool, 0, 4.5, true ) );

  // kings
  heads.push_back( cards[13] );
  heads.push_back( cards[27] );
  heads.push_back( cards[41] );
  heads.push_back( cards[55] );

  // queens
  heads.push_back( cards[12] );
  heads.push_back( cards[26] );
  heads.push_back( cards[40] );
  heads.push_back( cards[54] );

  // knights
  heads.push_back( cards[11] );
  heads.push_back( cards[25] );
  heads.push_back( cards[39] );
  heads.push_back( cards[53] );

  // jacks
  heads.push_back( cards[10] );
  heads.push_back( cards[24] );
  heads.push_back( cards[38] );
  heads.push_back( cards[52] );

  numberHearts		= 14;
  numberSpades		= 14;
  numberDiamonds	= 14;
  numberClubs		= 14;
  numberTrumps		= 21;
}

void Deck::shuffle()
{
  // random_shuffle( cards.begin(), cards.end() );
  std::shuffle( cards.begin(), cards.end(), default_random_engine( _seed ) );
}
