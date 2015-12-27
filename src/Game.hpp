/*
 * Tarot is an application for Android system to play to French Tarot.
 * Please visit https://github.com/richoux/Tarot for further information.
 * 
 * Copyright (C) 2013-2014 Florian Richoux
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
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <memory>
#include <cstdlib>

#include <Suits.hpp>
#include <Biddings.hpp>
#include <Team.hpp>
#include <Player.hpp>
#include <Human.hpp>
#include <AI.hpp>
#include <Card.hpp>
// #include <StratLang.hpp>
#include <Trick.hpp>
#include <Deck.hpp>

using namespace std; 

//! Game is one of the main class of Tarot. Here are defined rules, games' turns, scores, etc. 
class Game
{
public:
  
  //! The unique constructor of Game.
  /*!
    \param numberPlayers The number of players.
    \param yourName The human player name.
    \param automatic A boolean set to true if and only if one wants to perform automatic tests (4 bots playing together). False by default.
  */
  Game( int& numberPlayers, const string yourName = "You", const bool automatic = false );

  //! Creates a new game.
  void newGame();

  //! Prints players' / teams' scores.
  void printScores() const;

  //! Plays all turns of a game and returns the winner team.
  Team play();

  //! Shows the deck on the screen.
  void showDeck() const;

  //! Shows players' cards on the screen
  void showPlayersCards() const;

  //! Shuffles (three time) the deck.
  void shuffleDeck();

  //! Deals cards.
  void dealCards();

  //! Makes all players bidding.
  void takeBiddings();

  //! To take the dog after biddings.
  void takeDog();

  //! In a 5-player game, to choose as a partner the player having the called king (or card). 
  void chooseKing();

  //! Determines if two players belong to the same team.
  /*!
    \param p1 A player.
    \param p2 Another player.
    \return True iff p1 and p2 belong to the same team.
  */
  bool sameTeam( shared_ptr<Player> p1, shared_ptr<Player> p2 ) const;

  //! Computes the score of a given player (refered by his/her name).
  /*!
    \param name A string for a player's name.
    \return The score of the given player.
  */
  double computeScore( const string& name ) const;

private:
  //! To change the value of the current player's pointer.
  void nextPlayer();

  //! To set the current player (the next to play).
  /*!
    \param player The player assigned to be the next to play.
  */
  void setNext( shared_ptr<Player> player );

  //! At the end of a trick, add it to the heap of won cards by the winner of the trick.
  /*!
    \param name The name of the trick winner.
    \param cards The set of cards from the won trick.
  */
  void addWonCards( const string& name, const set<shared_ptr<Card> >& cards );

  //! Ensures to not lose the Fool, unless a very specific case: playing it at the very last trick without a chelem.
  void swapFool();

  void isCardCalled( shared_ptr<Card> card, shared_ptr<Player> player );
  
  vector< shared_ptr<Player> >	players;		//!< The vector of players.
  map< string, set<shared_ptr<Card> > > cardsPlayer;	//!< Won cards of each player.
  // shared_ptr<StratLang>		language;
  shared_ptr<Trick>		currentTrick;		//!< The current trick.
  stack< shared_ptr<Trick> >	history;		//!< The tricks history. 
  shared_ptr<Player>		next;			//!< A pointer on the next player to play.
  int				indexNext;		//!< Index of the next player to play. 
  int				indexStarter;		//!< ???
  int				indexToBid;		//!< Index of the next player to bid.
  int				indexBidder;		//!< Index of the best bidder.
  Deck				deck;			//!< The game deck.
  set< shared_ptr<Card> >	dog;			//!< The dog.
  Team				takers;			//!< The team with the best bid.
  Team				defenders;		//!< The non-taking team.
  Team				unknown;		//!< In a 5-player game, we don't know in which team are players, except the best bidder.
  Biddings			bidding;		//!< The type of bidding for its game.
  shared_ptr<Card>		kingCalled;		//!< In a 5-player game, which king (or card) has been called.
  bool				kingFound;		//!< True iff the king (or card) called is known.
  int				dogSize;		//!< The dog size, depending of the number of players.
  int				cardsPerPlayer;		//!< The number of cards each player has in its initial hand, depending also of the number of players.
  int				consecutiveDealing;	//!< How many cards the dealer must give to players consecutively.
  bool				chelemAnnounced;	//!< A boolean set to true iff a chelem has been announced.
  bool				addDogAtTheEnd;		//!< A boolean set to true iff the defender must keep the dog for them (in the case of a "guard against").

  bool				toSwap;			//!< True iff one must retakes its Fool card.
  bool				botsOnly;		//!< For debugging purpose. True means bots are playing together. False allows printing human player cards at the beginning of the game.
  shared_ptr<Player>		foolGiver;		//!< The player from who one must retake the Fool card.
  shared_ptr<Player>		foolReceiver;		//!< The former owner of the Fool card.
};
