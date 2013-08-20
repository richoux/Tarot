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

Human::Human( string name ) : Player( name ) {}
Human::~Human() {}

shared_ptr<Card> Human::playCard( shared_ptr<Card> card )
{
  return card;
}

void Human::newGame() 
{
  score = 0;
  hearts.clear();
  spades.clear();
  diamonds.clear();
  clubs.clear();
  trumps.clear();
  fool.reset();
}
