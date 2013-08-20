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

#include <AI.hpp>

AI::AI( string name, vector<string> knownPartners ) : Player( name )
{
  for( string partner : knownPartners )
    if( !partner.compare( name ) == 0 )
      partners[partner];
}

AI::~AI() {}

bool AI::isOpponent( string name )
{
  map<string, Counting>::const_iterator it;
  for( it = opponents.begin(); it != opponents.end(); ++it )
    if( it->first.compare( name ) == 0 )
      return true;

  return false;
}

bool AI::isPartner( string name )
{
  map<string, Counting>::const_iterator it;
  for( it = partners.begin(); it != partners.end(); ++it )
    if( it->first.compare( name ) == 0 )
      return true;

  return false;
}

bool AI::haveColor( string player, Colors color )
{
  if( isOpponent( player ) )
    return opponents[player].hasColor( color );
  else if( isPartner( player ) )
    return partners[player].hasColor( color );
  else
    return true;
}

bool AI::opponentsHaveColor( Colors color )
{
  map<string, Counting>::const_iterator it;
  for( it = opponents.begin(); it != opponents.end(); ++it )
    if( it->second.hasColor( color ) )
      return true;

  return false;
}

shared_ptr<Card> AI::playCard( shared_ptr<Card> card )
{
  return card;
}

void AI::newGame() 
{
  score = 0;
  hearts.clear();
  spades.clear();
  diamonds.clear();
  clubs.clear();
  trumps.clear();
  fool.reset();

  partners.clear();
  opponents.clear();
  cardCounting.newDeal();
}
