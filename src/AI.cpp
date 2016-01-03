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

#include <AI.hpp>

AI::AI( const string& name, const vector<string>& knownPartners ) : Player( name )
{
  for( string partner : knownPartners )
    if( partner.compare( name ) != 0 )
      partners[partner] = make_shared<Counting>();

  difficulty = make_shared<Beginner>();
}

bool AI::haveSuit( const string& name, const Suits suit ) const
{
  if( isOpponent( name ) )
    return opponents.at( name )->hasSuit( suit );
  else if( isPartner( name ) )
    return partners.at( name )->hasSuit( suit );
  else
    return true;
}

bool AI::opponentsHaveSuit( const Suits suit ) const
{
  return any_of(opponents.cbegin(), 
		opponents.cend(), 
		[&]( const map<string, shared_ptr<Counting> >::value_type counting){ return counting.second->hasSuit( suit ); } );

  // for( auto it = opponents.begin(); it != opponents.end(); ++it )
  //   if( it->second.hasSuit( suit ) )
  //     return true;

  // return false;
}

shared_ptr<Card> AI::playCard( shared_ptr<Card> referenceCard, shared_ptr<Card> highTrump )
{
  // cout << "Cards of " << name << ": ";
  // showCards();
  // cout << endl;

  // cout << "Player " << name << " valid cards: ";
  // for( shared_ptr<Card> card : validCards( referenceCard, highTrump ) )
  //   cout << *card;
  // cout << endl;

  shared_ptr<Card> theCard = difficulty->playCard( validCards( referenceCard, highTrump ) );
  
  assert( theCard != nullptr );
  
  cout << name << " played " << *theCard << endl;
  delCard( theCard );
  return theCard;
}

Biddings AI::bid( const Biddings bestBid, const bool chelemAnnounced ) const
{
  if( bestBid == Biddings::guard_a )
    return Biddings::none;

  // manage chelem announcement here

  return difficulty->bid( bestBid, getNumberOudlers(), chelemAnnounced );
}

set< shared_ptr<Card> >	AI::makeEcart( const int dogSize )
{
  set< shared_ptr<Card> > ecart = difficulty->makeEcart( dogSize, getInitialCards() );

  assert( ecart.size() == dogSize );
  
  for( auto card : ecart)
    delCard( card );
  return ecart;
}

shared_ptr<Card> AI::chooseKing( const Deck &deck ) const
{
  auto callable = callableCards( deck );
  return callable[ rand() % callable.size() ];
}

void AI::newGame() 
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

  partners.clear();
  opponents.clear();
  cardCounting.newDeal();
}
