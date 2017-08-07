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

#include <vector>
#include <stack>
#include <set>
#include <map>
#include <memory>

#include "Suits.hpp"
#include "Biddings.hpp"
#include "Team.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "AI.hpp"
#include "Card.hpp"
// #include "StratLang.hpp"
#include "Trick.hpp"
#include "Deck.hpp"

using namespace std; 

//! Game is one of the main class of Tarot. Here are defined rules, games' turns, scores, etc. 
class Game
{
public:

  //! The default constructor
  Game();
  
  //! The complete constructor of Game.
  /*!
    \param numberPlayers The number of players.
    \param yourName The human player name.
    \param automatic A boolean set to true if and only if one wants to perform automatic tests. False by default.
  */
  Game( int& numberPlayers, const bool automatic = false );

  //! In a 5-player game, to choose as a partner the player having the called king (or card). 
  void chooseKing();

  //! To call once bids are over.
  /*!
    \param bestBig The best bid among players.
    \return The score of the given player.
  */
  void closeBiddings( const Biddings bestBid );

  //! Computes the score of a given player (refered by his/her name).
  /*!
    \param name A string for a player's name.
    \return The score of the given player.
  */
  double computeScore( const string& name ) const;

  //! Deals cards.
  void dealCards();

  //! Close a game and returns winners.
  Team endGame();

  //! Inline function returning the game bid.
  inline Biddings getBidding() const { return bidding; }

  //! Inline function returning the number of cards players have to play in the game.
  inline int getCardsPerPlayer() const { return cardsPerPlayer; }

  //! Inline function returning the current trick.
  inline shared_ptr<Trick> getCurrentTrick() const { return currentTrick; }

  //! Inline function returning the defender team.
  inline Team getDefenders() const { return defenders; }

  //! Inline function returning the dog.
  inline set< shared_ptr<Card> >getDog() const { return dog; }

  //! Inline function returning the called king.
  inline shared_ptr<Card> getKingCalled() const { return kingCalled; }

  //! Inline function returning bidder's index.
  inline int getIndexBidder() const { return indexBidder; }

  //! Inline function returning next player's index.
  inline int getIndexNext() const { return indexNext; }

  //! Inline function returning starter player's index.
  inline int getIndexStarter() const { return indexStarter; }

  //! Inline function returning the index of the next player to bid.
  inline int getIndexToBid() const { return indexToBid; }

  //! Inline function returning the number of players.
  inline int getNumberPlayers() const { return players.size(); }

  //! Inline function returning the players vector.
  inline vector< shared_ptr<Player> > getPlayers() const { return players; }

  //! Returns won cards of a given player.
  /*!
    \param players The player we want won cards from.
    \return The set containing his/her won cards.
  */
  set<shared_ptr<Card> >getPlayerWonCards( const shared_ptr<Player> player ) const;

  //! Inline function returning the taker team.
  inline Team getTakers() const { return takers; }

  //! Update some fields and returns the current trick.
  shared_ptr<Trick> getTrick();
  
  //! Inline function returning the unknown team (only in a 5-player game).
  inline Team getUnknownTeam() const { return unknown; }

  //! Inline function returning if it is a game without any human players.
  inline bool isBotsOnly() const { return botsOnly; }

  //! Inline function returning if it the called king is known.
  inline bool isKingFound() const { return kingFound; }

  //! Creates a new game.
  void newGame();

  //! Prints players' / teams' scores.
  void printScores() const;

  //! Plays one player turn part of the current trick and returns the played card.
  /*!
    \param kingJustFound The reference to a Boolean value set to true iff the played card is the called king. 
    \return The played card.
  */
  shared_ptr< Card > playCard( bool &kingJustFound );

  //! Determines if two players belong to the same team.
  /*!
    \param p1 A player.
    \param p2 Another player.
    \return True iff p1 and p2 belong to the same team.
  */
  bool sameTeam( const shared_ptr<Player> p1, const shared_ptr<Player> p2 ) const;

  //! Set a game, like the equivalent constructor does.
  void setGame( int& numberPlayers, const bool automatic = false );
  
  //! Shows the deck on the screen.
  void showDeck() const;

  //! Shows players' cards on the screen.
  void showPlayersCards() const;

  //! Shuffles (three time) the deck.
  void shuffleDeck();

  //! Makes the current player bidding, then turns to the next player.
  /*!
    \param bestBid the reference to the best bid made so far.
    \return The pair <player, bid>.
  */
  pair< shared_ptr<Player>, Biddings > takeBiddings( const Biddings &bestBid );

  //! To take the dog after biddings.
  void takeDog();

  //! Inline function setting indexBidder to the value of indexToBid.
  inline void updateIndexBidder() { indexBidder = indexToBid; }

private:
  //! At the end of a trick, add it to the heap of won cards by the winner of the trick.
  /*!
    \param name The name of the trick winner.
    \param cards The set of cards from the won trick.
  */
  void addWonCards( const string& name, const set<shared_ptr<Card> >& cards );

  //! Check if a played card is the called king in a 5-player game.
  /*!
    \param card The played card to check.
    \param player The player who played card.
    \return True iff card is the called king.
  */
  bool isCardCalled( const shared_ptr<Card> card, const shared_ptr<Player> player );

  //! To change the value of the current player's pointer.
  void nextPlayer();

  //! To set the current player (the next to play).
  /*!
    \param player The player assigned to be the next to play.
  */
  void setNext( const shared_ptr<Player> player );

  //! Ensures to not lose the Fool, unless a very specific case: playing it at the very last trick without a chelem.
  void swapFool();
  
  //! Update Game fields after each trick.
  void update();

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
  size_t			dogSize;		//!< The dog size, depending of the number of players.
  int				cardsPerPlayer;		//!< The number of cards each player has in its initial hand, depending also of the number of players.
  int				consecutiveDealing;	//!< How many cards the dealer must give to players consecutively.
  bool				chelemAnnounced;	//!< A boolean set to true iff a chelem has been announced.
  bool				addDogAtTheEnd;		//!< A boolean set to true iff the defender must keep the dog for them (in the case of a "guard against").

  bool				toSwap;			//!< True iff one must retakes its Fool card.
  bool				botsOnly;		//!< For debugging purpose. True means bots are playing together. False allows printing human player cards at the beginning of the game.
  shared_ptr<Player>		foolGiver;		//!< The player from who one must retake the Fool card.
  shared_ptr<Player>		foolReceiver;		//!< The former owner of the Fool card.
};
