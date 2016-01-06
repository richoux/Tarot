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

#include <sstream>

#include <Card.hpp>

Card::Card( const Suits suit, const int value, const double points, const bool oudler )
  : suit(suit), value(value), points(points), oudler(oudler)
{}

int Card::computeIndex() const
{
  switch( suit )
  {
  case heart:
    return value;
  case spade:
    return 13 + value;
  case diamond:
    return 27 + value;
  case club:
    return 41 + value;
  case trump:
    return 55 + value;
  default: // fool
    return 77;
  }
}

bool Card::operator>( const Card& card ) const 
{ 
  if( this->suit == 4 && card.suit < 4)
    return true;
  else if( this->suit < 4 && card.suit == 4)
    return false;
  else
    return this->value > card.value;
}

bool Card::operator<( const Card& card ) const
{ 
  if( this->suit == 4 && card.suit < 4)
    return false;
  else if( this->suit < 4 && card.suit == 4)
    return true;
  else
    return this->value < card.value;
}

bool Card::operator==( const Card& card ) const 
{ 
  return this->suit == card.suit && this->value == card.value;
}

ostream& operator<<( ostream& os, const Card& card )
{
  string col;
  string val;

  ostringstream oss;
 
  switch( card.value )
  {
  case 1:
    val = "A";
    break;
  case 11:
    val = "J";
    break;
  case 12:
    val = "Kn";
    break;
  case 13:
    val = "Q";
    break;
  case 14:
    val = "K";
    break;
  default:
    oss << card.value;
    val = oss.str();
    break;
  }

  switch( card.suit )
  {
  case heart:
    col = "♥";
    break;
  case spade:
    col = "♠";
    break;
  case diamond:
    col = "♦";
    break;
  case club:
    col = "♣";
    break;
  case trump:
    col = "T";
    if( card.value == 1 )
      val = "1";
    else if( card.value == 11 )
      val = "11";
    else if( card.value == 12 )
      val = "12";
    else if( card.value == 13 )
      val = "13";
    else if( card.value == 14 )
      val = "14";
    break;
  case fool:
    col = "F";
    val = "";
    break;
  default:
    col = "Unkwown card";
    val = "";
  }

  os << val + col + "  ";
  return os;
}
