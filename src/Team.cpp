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

#include "Team.hpp"

double Team::getScore() const
{
  double score = 0;

  for( auto it = members.begin(); it != members.end(); ++it )
    score += it->second->score;

  return score;
}

bool Team::isEmpty() const
{
  return members.empty();
}

void Team::newGame() 
{
  members.clear();
}

bool Team::operator<( const Team &team ) const
{
  return this->getScore() < team.getScore();
}

bool Team::operator>( const Team &team ) const
{
  return this->getScore() > team.getScore();
}

ostream& operator<<( ostream& os, const Team& team )
{
  string names = "";
  for( auto it = team.members.begin(); it !=team.members.end(); ++it )
    if( it == team.members.begin() )
      names += it->first;
    else
      names += ", " + it->first;

  os << names;
  return os;
}
