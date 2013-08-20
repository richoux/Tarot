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
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 11, 1.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 12, 2.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 13, 3.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 14, 4.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::heart, 1, 0.5, false) ) );

  // Spades
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 11, 1.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 12, 2.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 13, 3.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 14, 4.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::spade, 1, 0.5, false) ) );

  // Diamonds
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 11, 1.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 12, 2.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 13, 3.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 14, 4.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::diamond, 1, 0.5, false) ) );

  // Clubs
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 11, 1.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 12, 2.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 13, 3.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 14, 4.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::club, 1, 0.5, false) ) );

  // Trumps
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 1, 4.5, true) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 2, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 3, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 4, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 5, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 6, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 7, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 8, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 9, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 10, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 11, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 12, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 13, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 14, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 15, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 16, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 17, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 18, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 19, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 20, 0.5, false) ) );
  cards.push_back( shared_ptr<Card>( new Card(Colors::trump, 21, 4.5, true) ) );

  // Fool
  cards.push_back( shared_ptr<Card>( new Card(Colors::fool, 0, 4.5, true) ) );

  numberHearts		= 14;
  numberSpades		= 14;
  numberDiamonds	= 14;
  numberClubs		= 14;
  numberTrumps		= 21;
}

bool Deck::isInDeck( shared_ptr<Card> card )
{
  vector< shared_ptr<Card> >::const_iterator it;
  for( it = cards.begin(); it != cards.end(); ++it )
    if( *it == card)
      return true;

  return false;
}

bool Deck::hasStrongerThan( shared_ptr<Card> card )
{
  vector< shared_ptr<Card> >::const_iterator it;
  for( it = cards.begin(); it != cards.end(); ++it )
    if( *it > card)
      return true;

  return false;  
}