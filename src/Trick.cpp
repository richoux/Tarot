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

#include <Trick.hpp>

Trick::Trick( shared_ptr<Card> kingCalled) : kingCalled(kingCalled), leader(nullptr), greaterTrump(nullptr) 
{}

Trick::~Trick() 
{
  trickCards.clear();
}

vector< shared_ptr<Card> > Trick::getAllCards()
{
  vector< shared_ptr<Card> > allCards;
  
  for( auto it = trickCards.begin(); it != trickCards.end(); ++it )
    allCards.push_back( it->second );
  
  return allCards;
}

double Trick::getScore()
{
  double score = 0;
  vector< shared_ptr<Card> > allCards = getAllCards();

  for( shared_ptr<Card> card : allCards )
    score += card->getPoints();

  return score;
}

void Trick::setCard( shared_ptr<Player> player, shared_ptr<Card> card )
{
  trickCards[player] = card;
  if( leader == nullptr || card > trickCards[leader] )
    leader = player;

  if( card->isTrump() && ( greaterTrump == nullptr || card > greaterTrump ) )
    greaterTrump = card;
}

shared_ptr<Player> Trick::asCalledKing()
{
  for( auto it = trickCards.begin(); it != trickCards.end(); ++it)
    if( it->second == kingCalled )
      return it->first;

  return nullptr;
}
