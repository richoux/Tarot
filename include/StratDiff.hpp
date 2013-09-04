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

#include <vector>
#include <set>
#include <memory>

#include <Card.hpp>
#include <Biddings.hpp>

using namespace std;

class StratDiff
{
public:
  virtual shared_ptr<Card>		playCard( vector< shared_ptr<Card> > )		= 0;
  virtual Biddings			bid	( Biddings, int, bool )			= 0;
  virtual set< shared_ptr<Card> >	makeEcart( int, vector< shared_ptr<Card> > )	= 0;
};
