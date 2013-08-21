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

void Player::addCard( shared_ptr<Card> card )
{
  switch( card->getColor() )
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
    case Colors::fool:
      fool = card;
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
