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

#include <Human.hpp>

Human::Human( const string& name ) : Player( name ) {}
Human::~Human() {}

shared_ptr<Card> Human::playCard( shared_ptr<Card> referenceCard, shared_ptr<Card> highTrump )
{
  vector< shared_ptr<Card> > valids = validCards( referenceCard, highTrump );

  cout << "My cards: ";
  showCards();
  cout << endl;
  
  for( unsigned int i = 0; i < valids.size(); i++ )
    cout << "(" << i << ") " << *valids[i] << " | ";
  
  int index;
  
  do
  {
    index = getInt( "\nSelect your card: " );
  }
  while( index < 0 || index >= valids.size() );

  cout << "You played " << *valids[index] << endl;
  delCard( valids[index] );
  return valids[index];
}

Biddings Human::bid( const Biddings bestBid, const bool chelemAnnounced ) const
{
  cout << "My cards: ";
  showCards();
  cout << endl;

  if( bestBid == Biddings::guard_a )
  {
    cout << "Impossible to bid, Guard Against has been chosen" << endl;
    return Biddings::none;
  }
  else
  {
    char choice;
    cout << "Biddings: (p)Pass, ";
    if( bestBid == Biddings::none )
    {
      cout << "(s)Small, (g)Guard, (w)Guard Without, (a)Guard Against" << endl;
      do
      {
	choice = getChar( "\nSelect your choice: " );
      }
      while( choice != 'p' && choice != 's' && choice != 'g' && choice != 'w' && choice != 'a' );
    }
    else if( bestBid == Biddings::small )
    {
      cout << "(g)Guard, (w)Guard Without, (a)Guard Against" << endl;
      do
      {
	choice = getChar( "\nSelect your choice: " );
      }
      while( choice != 'p' && choice != 'g' && choice != 'w' && choice != 'a' );
    }
    else if( bestBid == Biddings::guard )
    {
      cout << "(w)Guard Without, (a)Guard Against" << endl;
      do
      {
	choice = getChar( "\nSelect your choice: " );
      }
      while( choice != 'p' && choice != 'w' && choice != 'a' );
    }
    else 
    {
      cout << "(a)Guard Against" << endl;
      do
      {
	choice = getChar( "\nSelect your choice: " );
      }
      while( choice != 'p' && choice != 'a' );
    }
      
    switch( choice )
    {
    case 'p':
      return Biddings::none;
    case 's':
      return Biddings::small;
    case 'g':
      return Biddings::guard;
    case 'w':
      return Biddings::guard_w;
    case 'a':
      return Biddings::guard_a;
    default:
      return Biddings::none;
    }
  }  
}

set< shared_ptr<Card> >	Human::makeEcart( const int dogSize )
{
  set< shared_ptr<Card> > ecart;

  cout << "Make your ecart." << endl;
  
  for( unsigned int i = 0; i < getInitialCards().size(); i++ )
    cout << "(" << i << ") " << *getInitialCards()[i] << " | ";

  int index;

  while( ecart.size() < dogSize )
  {
    do
    {
      index = getInt( "\nSelect a card: " );
    }
    while( index < 0 || index >= getInitialCards().size() );
      
    if( ecart.find( getInitialCards()[index] ) == ecart.end() )
      ecart.insert( getInitialCards()[index] );
    else
      cout << "You already choose this card. Please select a new one." << endl;
  }

  return ecart;
}

void Human::newGame() 
{
  score = 0;
  numberOudlers = 0;
  initialPoints = 0;

  hearts.clear();
  spades.clear();
  diamonds.clear();
  clubs.clear();
  trumps.clear();
  fool.reset();
  initialCards.clear();
}

