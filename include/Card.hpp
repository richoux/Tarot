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

#pragma once

#include <iostream>
#include <memory>

#include <Colors.hpp>

using namespace std;

class Card
{
  friend ostream& operator<<	( ostream&, const Card& );

public:
  Card( Colors, int, double, bool );
  ~Card();

  inline double	getPoints	() { return points; }
  inline Colors getColor	() { return color; }
  inline int	getValue	() { return value; }
  inline bool	isOudler	() { return oudler; }
  inline bool	isFaceCard	() { return value > 10; }

  bool		operator>	( shared_ptr<Card> );
  bool		operator<	( shared_ptr<Card> );
  bool		isComparable	( shared_ptr<Card> );

private:
  Colors	color;
  int		value;
  double	points;
  bool		oudler;
};