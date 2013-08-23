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

#include <Player.hpp>

Player::Player( string name ) : name(name) {}
Player::Player( const Player &player ) {}
Player::~Player() {}

vector< shared_ptr<Card> > Player::validCards( shared_ptr<Card> refCard, shared_ptr<Card> greaterTrump )
{
  vector< shared_ptr<Card> > returnCards;

  if( refCard == nullptr || refCard->isFool() )
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
      switch( refCard->getSuit() )
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
  
  return returnCards;
}

void Player::addCard( shared_ptr<Card> card )
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
}

void Player::delCard( shared_ptr<Card> card )
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

void Player::showCards()
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
