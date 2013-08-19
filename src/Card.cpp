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

#include <Card.hpp>

Card::Card( Colors color, int value, double points, bool oudler )
  : color(color), value(value), points(points), oudler(oudler)
{}

Card::~Card() {}

inline double	Card::getPoints	() { return points; }
inline bool	Card::isOudler	() { return oudler; }
inline bool	Card::isFaceCard() { return value > 10; }

bool		Card::operator>	( shared_ptr<Card> card ) 
{ 
  if( this->color == 4 && card->color < 4)
    return true;
  else if( this->color < 4 && card->color == 4)
    return false;
  else
    return this->value > card->value;
}

bool		Card::operator<	( shared_ptr<Card> card ) 
{ 
  if( this->color == 4 && card->color < 4)
    return false;
  else if( this->color < 4 && card->color == 4)
    return true;
  else
    return this->value < card->value;
}

inline bool	Card::isComparable ( shared_ptr<Card> card ) 
{ 
  return this->color == card->color || this->color == 4 || card->color == 4;
}
