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

#pragma once

#include <map>
#include <memory>

#include "Player.hpp"

using namespace std;

//! Team is the class handling team management.
class Team
{
  //! Used to simplify team screen printings.
  friend ostream& operator<<	( ostream&, const Team& );

public:
  //! Inline function to test if a player belongs to this team
  /*!
    \param name The considered player name.
    \reutrn True iff the team contains the given player.
  */
  inline bool contains ( const string& name ) const { return members.find( name ) != members.end(); }

  //! Assessor returning the team's score.
  double getScore() const;

  //! Return if the Team is empty
  bool isEmpty() const;

  //! To prepare a new game.
  void newGame();

  //! To compare two teams regarding their score.
  bool operator>( const Team& t ) const;

  //! To compare two teams regarding their score.
  bool operator<( const Team& t ) const;
  

  map<string, shared_ptr<Player> > members; //!< A map of team members, to quickly have an hand on the player object knowing his/her name.
};
