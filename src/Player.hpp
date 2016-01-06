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

#include <set>
#include <vector>
#include <memory>

#include "Card.hpp"
#include "Deck.hpp"
#include "Biddings.hpp"
#include "Announcements.hpp"

using namespace std;

//! Player is an abstract class presenting a common interface for AI and Human players.
class Player
{
public:
  //! The unique constructor of Player.
  /*!
    \param name The player name.
  */
  Player( const string& name );

  //! Add a card among player's initial cards.
  /*!
    \param card The card to add.
  */
  void addCard( const shared_ptr<Card> card );

  //! Pure virtual function to make a choice for biddings.
  /*!
    \param bestBid The best bid proposed so far.
    \param chelemAnnounced A Boolean to know if someone has declared a chelem.
    \return The chosen bid (Biddings::none if one passes).
  */
  virtual Biddings bid( const Biddings bestBid, const bool chelemAnnounced ) const = 0;

  //! Pure virtual function to make a choice for partnership in a 5-player game.
  /*!
    \param deck The current deck used for the game
    \return The chosen king (or card).
  */
  virtual shared_ptr<Card> chooseKing( const Deck &deck ) const = 0;

  //! Returns all cards in player's hand.
  /*!
    \return The union of hearts, spades, etc, sets.
  */
  set< shared_ptr<Card> > getAllCards() const;

  //! Inline assessor to the set of announcements.
  inline  set< Announcements > getAnnounced() const { return announced; }

  //! Inline assessor to the player's initial cards.
  inline  vector< shared_ptr<Card> > getInitialCards() const { return initialCards; }

  //! Inline assessor to the number of oudlers the player has with his/her initial hand.
  inline  int getNumberOudlers() const { return numberOudlers; }

  //! Pure virtual function to make the ecart when the player is the best bidder.
  /*!
    \param dogSize The number of card one must include into the ecart.
    \return A set of Card pointers for the cards one places into the ecart.
  */
  virtual set< shared_ptr<Card> > makeEcart( const int dogSize ) = 0;

  //! Pure virtual function to prepare the player for a new game. 
  virtual void newGame() = 0;

  //! playCard is a pure virtual function returning the card the player chooses to play.  
  /*!
    \param referenceCard The card fixing the ask suit for the trick.
    \param highTrump The highest trump played so far for the trick, if any.
    \return The chosen card to play.
  */
  virtual shared_ptr<Card> playCard( const shared_ptr<Card> referenceCard, const shared_ptr<Card> highTrump ) = 0;

  //! To print all player's cards in his/her current hand. 
  void showCards() const;

  //! Returns the vector of cards the player can currently play, regarding the asked suit and the greater trump of the trick.
  /*!
    \param refCard A pointer of the card fixing the asked suit of the trick.
    \param greaterTrump A pointer on the greater trump of the trick, if any.
    \return The vector of all cards the player can play in his/her situation. 
  */
  vector< shared_ptr<Card> > validCards	( const shared_ptr<Card> refCard, const shared_ptr<Card> greaterTrump ) const;

  string name; //!< The player's name. 
  double score; //!< The player's score.

protected:
  //! To compute the vector of cards we can call during a 5-player game.
  /*!
    \param deck The deck used form the game.
    \return The vector of cards the taker can call (usually, the four kings).
  */
  vector< shared_ptr<Card> > callableCards( const Deck &deck ) const;  

  //! To delete a card from the player's current hand.
  /*!
    \param card The card to delete from the player's hand.
  */
  void delCard( const shared_ptr<Card> card );

  //! A structure to automatically fix an insert order into cards' sets. 
  struct cardOrder {
    bool operator() ( const shared_ptr<Card> lhs, const shared_ptr<Card> rhs) const
      {
	return lhs->getValue() < rhs->getValue();
      }
  };

  set< shared_ptr<Card>, cardOrder >	hearts;		//!< The set of Hearts owned by the player.
  set< shared_ptr<Card>, cardOrder >	spades;		//!< The set of Spades owned by the player.
  set< shared_ptr<Card>, cardOrder >	diamonds;	//!< The set of Diamonds owned by the player.
  set< shared_ptr<Card>, cardOrder >	clubs;		//!< The set of Clubs owned by the player.
  set< shared_ptr<Card>, cardOrder >	trumps;		//!< The set of trumps owned by the player.
  shared_ptr<Card>			fool;		//!< The pointer toward the Fool, if owned by the player.
  vector< shared_ptr<Card> >		initialCards;	//!< The vector of player's initial cards, from his/her starting hand.
  int					numberOudlers;	//!< The number of oudlers the player has among his/her initial cards.
  double				initialPoints;	//!< The number of points the player has with his/her initial cards.
  set< Announcements >			announced;	//!< The set of announcements (for what?).

private:
  bool hasCard( const shared_ptr<Card> card ) const;
};
