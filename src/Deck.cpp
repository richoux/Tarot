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

#include <Deck.hpp>

Deck::Deck() 
{
  newDeal();
}

Deck::~Deck() 
{
  cards.clear();
}

void Deck::newDeal()
{
  cards.clear();

  // Hearts
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 11, 1.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 12, 2.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 13, 3.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 14, 4.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::heart, 1, 0.5, false) ) );

  // Spades
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 11, 1.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 12, 2.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 13, 3.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 14, 4.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::spade, 1, 0.5, false) ) );

  // Diamonds
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 11, 1.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 12, 2.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 13, 3.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 14, 4.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::diamond, 1, 0.5, false) ) );

  // Clubs
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 11, 1.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 12, 2.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 13, 3.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 14, 4.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::club, 1, 0.5, false) ) );

  // Trumps
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 1, 4.5, true) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 11, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 12, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 13, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 14, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 15, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 16, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 17, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 18, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 19, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 20, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Suits::trump, 21, 4.5, true) ) );

  // Fool
  cards.push_back( shared_ptr<Card>( new Card(Suits::fool, 0, 4.5, true) ) );

  numberHearts		= 14;
  numberSpades		= 14;
  numberDiamonds	= 14;
  numberClubs		= 14;
  numberTrumps		= 21;
}

void Deck::shuffle()
{
  random_shuffle( cards.begin(), cards.end() );
}

bool Deck::isInDeck( shared_ptr<Card> card ) const
{
  for( auto it = cards.begin(); it != cards.end(); ++it )
    if( *it == card)
      return true;

  return false;
}

bool Deck::hasStrongerThan( shared_ptr<Card> card ) const
{
  for( auto it = cards.begin(); it != cards.end(); ++it )
    if( *(*it) > *card)
      return true;

  return false;  
}
