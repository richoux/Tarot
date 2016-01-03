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

#include <iostream>
#include <memory>

#include <Suits.hpp>

using namespace std;

//! Card is the class compiling all useful information on cards: points, suit, value...
class Card
{
  //! Surcharging << to make std::cout easier. 
  friend ostream& operator<< ( ostream&, const Card& );

public:
  //! The unique constructor for Card.
  /*!
    \param suit The card's suit.
    \param value Its value (11, 12, 13 and 14 for a Jack, Knigh, Queen and King, respectively).
    \param points Its points, needing a real value.
    \param oudler A Boolean set to true iff the card is an oudler.
  */
  Card( const Suits suit, const int value, const double points, const bool oudler );

  //! Inline assessor to get the card's points.
  inline double	getPoints	() const { return points; }

  //! Inline assessor to get the card's suit.
  inline Suits	getSuit		() const { return suit; }

  //! Inline assessor to get the card's value.
  inline int	getValue	() const { return value; }

  //! Inline function returning true iif the card is the Fool.
  inline bool	isFool		() const { return suit == Suits::fool; }

  //! Inline function returning true iif the card is a trump.
  inline bool	isTrump		() const { return suit == Suits::trump; }

  //! Inline function returning true iif the card is an oudler.
  inline bool	isOudler	() const { return oudler; }

  //! Inline function returning true iif the card is a face card.
  inline bool	isFaceCard	() const { return value > 10; }

  //! A greater-than comparator to make easier the comparison between cards.
  /*! 
    \param card The card one's compared with.
    \return true iff the given card is smaller than the left hand side card.
    Cards must be comparable, i.e., from the same suit or be trump.
  */ 
  bool operator>( const Card& card ) const;

  //! A less-than comparator to make easier the comparison between cards.
  /*! 
    \param card The card one's compared with.
    \return true iff the given card is greater than the left hand side card.
    Cards must be comparable, i.e., from the same suit or be trump.
  */ 
  bool operator<( const Card& card ) const;

  //! An equal comparator to make easier the comparison between cards.
  /*! 
    \param card The card one's compared with.
    \return true iff the two cards are the same.
  */ 
  bool operator==( const Card& card ) const;

  //! A function to decide if two cards are comparable
  /*! 
    Decides if the two involved cards are comparable, i.e., from the same 
    suit or be trump.
    \param card Another card.
    \return True iff the two cards are comparable.
  */
  inline bool isComparable( const Card& card ) const 
    { 
      return this->suit == card.suit || this->suit == 4 || card.suit == 4;
    }

private:
  Suits		suit;	//!< The card's suit.
  int		value;	//!< The card's value.
  double	points;	//!< The card's point.
  bool		oudler;	//!< A Boolean to specify s the card iss an oudler or not.
};
