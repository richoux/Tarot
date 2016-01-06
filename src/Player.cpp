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

#include <iostream>
#include <algorithm>
#include <cassert>

#include "Player.hpp"

Player::Player( const string& name ) 
  : name( name ), 
    numberOudlers( 0 ), 
    initialPoints( 0 ) 
{}


/////////
// public

void Player::addCard( const shared_ptr<Card> card )
{
  switch( card->getSuit() )
  {
  case heart:
    hearts.insert( card );
    break;
  case spade:
    spades.insert( card );
    break;
  case diamond:
    diamonds.insert( card );
    break;
  case club:
    clubs.insert( card );
    break;
  case trump:
    trumps.insert( card );
    break;
  case Suits::fool:
    fool = card;
    break;
  default:
    break;
  }

  if( card->isOudler() )
    numberOudlers++;

  initialPoints += card->getPoints();
  initialCards.push_back( card );
}

set< shared_ptr<Card> > Player::getAllCards() const
{
  set< shared_ptr<Card> > allCards;
  allCards.insert( hearts.cbegin(), hearts.cend() );
  allCards.insert( spades.cbegin(), spades.cend() );
  allCards.insert( diamonds.cbegin(), diamonds.cend() );
  allCards.insert( clubs.cbegin(), clubs.cend() );
  allCards.insert( trumps.cbegin(), trumps.cend() );
  if( fool != nullptr )
    allCards.insert( fool );

  return allCards;
}

void Player::showCards() const
{
  // show trumps
  for( shared_ptr<Card> card : trumps )
    cout << *card;

  // show fool
  if( fool.get() != nullptr )
    cout << *fool;

  // show hearts
  for( shared_ptr<Card> card : hearts )
    cout << *card;

  // show spades
  for( shared_ptr<Card> card : spades )
    cout << *card;

  // show diamonds
  for( shared_ptr<Card> card : diamonds )
    cout << *card;

  // show clubs
  for( shared_ptr<Card> card : clubs )
    cout << *card;
}

vector< shared_ptr<Card> > Player::validCards( const Suits referenceSuit, const shared_ptr<Card> greaterTrump ) const
{
  vector< shared_ptr<Card> > returnCards;

  if( referenceSuit == Suits::unknown || referenceSuit == Suits::fool )
  {
    for( shared_ptr<Card> card : trumps )
      returnCards.push_back( card );
    for( shared_ptr<Card> card : hearts )
      returnCards.push_back( card );
    for( shared_ptr<Card> card : spades )
      returnCards.push_back( card );
    for( shared_ptr<Card> card : diamonds )
      returnCards.push_back( card );
    for( shared_ptr<Card> card : clubs )
      returnCards.push_back( card );
  }
  else
  {
    switch( referenceSuit )
    {
    case Suits::heart:
      if( !hearts.empty() )
      {
	for( shared_ptr<Card> card : hearts )
	  returnCards.push_back( card );
      }
      break;
    case Suits::spade:
      if( !spades.empty() )
      {
	for( shared_ptr<Card> card : spades )
	  returnCards.push_back( card );
      }
      break;
    case Suits::diamond:
      if( !diamonds.empty() )
      {
	for( shared_ptr<Card> card : diamonds )
	  returnCards.push_back( card );
      }
      break;
    case Suits::club:
      if( !clubs.empty() )
      {
	for( shared_ptr<Card> card : clubs )
	  returnCards.push_back( card );
      }
      break;
    case Suits::trump:
      if( !trumps.empty() )
      {
	for( shared_ptr<Card> card : trumps )
	  if( greaterTrump != nullptr && *card > *greaterTrump )
	    returnCards.push_back( card );
	// if we have trumps, but not better than the highest of the trick
	// OR, if no trumps have been played
	if( returnCards.empty() )
	  for( shared_ptr<Card> card : trumps )
	    returnCards.push_back( card );
      }
      break;
    default:
      break;
    }

    // occurs if one does not have the asked suit 
    if( returnCards.empty() )
    {
      if( !trumps.empty() )
      {
	for( shared_ptr<Card> card : trumps )
	  if( greaterTrump != nullptr && *card > *greaterTrump )
	    returnCards.push_back( card );
	// if we have trumps, but not better than the highest of the trick
	// OR, if no trumps have been played
	if( returnCards.empty() )
	  for( shared_ptr<Card> card : trumps )
	    returnCards.push_back( card );
      }
      // if one has no trumps
      else
      {
	for( shared_ptr<Card> card : hearts )
	  returnCards.push_back( card );
	for( shared_ptr<Card> card : spades )
	  returnCards.push_back( card );
	for( shared_ptr<Card> card : diamonds )
	  returnCards.push_back( card );
	for( shared_ptr<Card> card : clubs )
	  returnCards.push_back( card );
      }
    }
  }

  // We can always play the Fool if we have it
  if( fool != nullptr )
    returnCards.push_back( fool );

#if defined DEBUG
  if( returnCards.empty() )
  {
    cout << "Empty valid cards set!" << endl;
    showCards();
  }
#endif
  assert( !returnCards.empty() );
  
  return returnCards;
}


////////////
// protected

vector< shared_ptr<Card> > Player::callableCards( const Deck &deck ) const
{
  vector< shared_ptr<Card> > callable; 

  shared_ptr<Card> kingHeart = deck.heads[0];
  shared_ptr<Card> kingSpade = deck.heads[1];
  shared_ptr<Card> kingDiamond = deck.heads[2];
  shared_ptr<Card> kingClub = deck.heads[3];

  callable.push_back( kingHeart );
  callable.push_back( kingSpade );
  callable.push_back( kingDiamond );
  callable.push_back( kingClub );

  // if we have all four kings, we can ask for queens
  if( hasCard( kingHeart ) &&
      hasCard( kingSpade ) &&
      hasCard( kingDiamond ) &&
      hasCard( kingClub ) )
  {
    shared_ptr<Card> queenHeart = deck.heads[4];
    shared_ptr<Card> queenSpade = deck.heads[5];
    shared_ptr<Card> queenDiamond = deck.heads[6];
    shared_ptr<Card> queenClub = deck.heads[7];
    
    callable.push_back( queenHeart );
    callable.push_back( queenSpade );
    callable.push_back( queenDiamond );
    callable.push_back( queenClub );

    // if we have all four kings and queens, we can ask for knights
    if( hasCard( queenHeart ) &&
	hasCard( queenSpade ) &&
	hasCard( queenDiamond ) &&
	hasCard( queenClub ) )
    {
      shared_ptr<Card> knightHeart = deck.heads[8];
      shared_ptr<Card> knightSpade = deck.heads[9];
      shared_ptr<Card> knightDiamond = deck.heads[10];
      shared_ptr<Card> knightClub = deck.heads[11];
      
      callable.push_back( knightHeart );
      callable.push_back( knightSpade );
      callable.push_back( knightDiamond );
      callable.push_back( knightClub );
      
      // if we have all four kings, queens and knights,
      // we can ask for jacks
      if( hasCard( knightHeart ) &&
	  hasCard( knightSpade ) &&
	  hasCard( knightDiamond ) &&
	  hasCard( knightClub ) )
      {
	shared_ptr<Card> jackHeart = deck.heads[12];
	shared_ptr<Card> jackSpade = deck.heads[13];
	shared_ptr<Card> jackDiamond = deck.heads[14];
	shared_ptr<Card> jackClub = deck.heads[15];
	
	callable.push_back( jackHeart );
	callable.push_back( jackSpade );
	callable.push_back( jackDiamond );
	callable.push_back( jackClub );	
      }
    }
  }

  return callable;
}

void Player::delCard( const shared_ptr<Card> card )
{
  switch( card->getSuit() )
  {
  case heart:
    hearts.erase( card );
    break;
  case spade:
    spades.erase( card );
    break;
  case diamond:
    diamonds.erase( card );
    break;
  case club:
    clubs.erase( card );
    break;
  case trump:
    trumps.erase( card );
    break;
  case Suits::fool:
    fool = nullptr;
    break;
  default:
    break;
  }
}


//////////
// private

bool Player::hasCard( const shared_ptr<Card> card ) const 
{
  switch( card->getSuit() )
  {
  case Suits::heart:
    return hearts.find( card ) != hearts.end();
    
  case Suits::spade:
    return spades.find( card ) != spades.end();

  case Suits::diamond:
    return diamonds.find( card ) != diamonds.end();

  case Suits::club:
    return clubs.find( card ) != clubs.end();

  case Suits::trump:
    return trumps.find( card ) != trumps.end();

  case Suits::fool:
    return fool != nullptr;
    
  default:
    return false;
  }
}

