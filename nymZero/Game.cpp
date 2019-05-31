#include "stdafx.h"
#include "Game.h"
#include "Deck.h"
#include "Player.h"
#include <vector>
#include <random>
#include <iostream>
#include <string>

Game::Game(int numPlayers, int startingBalance, int maxCardValue, int cardCopies, int handSize, int threshold, unsigned seed) {
	this->threshold = threshold;
	deck = new Deck(maxCardValue, cardCopies);
	for (int p = 0; p < numPlayers - 1; p++) {
		players.push_back(Player(startingBalance, false));
		drawCardsTo(players.back(), handSize);
	}
	players.push_back(Player(startingBalance, true));
	drawCardsTo(players.back(), handSize);
	std::shuffle(players.begin(), players.end(), std::default_random_engine(seed));
	srand(seed);
}

void Game::drawCardsTo(Player player, int numCards) {
	for (int c = 0; c < numCards; c++) {
		player.addToHand(deck->draw());
	}
}

void Game::playRound() {
	//Print out the round's starting state
	int i = 1;
	for (Player player : players) {
		std::cout << (player.isHuman ? "Human " : "AI ");
		std::cout << "(turn order: " + std::to_string(i) + ") has " + player.getBalanceString() + "\n";
		i++;
	}
	std::cout << "\n";
	//Start betting phase
	for (Player player : players) {
		double bet;
		if (!player.isHuman) {
			bet = rand() % (int)player.getBalance() + 1;
			//std::cout << bet;
			player.bet(bet);
		}
		else { //TODO: input validation for 0 and negative bets
			std::cout << "How much do you want to bet? You have: " + player.getBalanceString() + "\n";
			std::cin >> bet;
			player.bet(bet);
		}
	}
	//Start playing phase
	for (Player player : players) {
		if (player.getHand().size() == 0) {
			break;
		}

		if (!player.isHuman) {
			//get a value based on hand
			int position = rand() % player.getHand().size();
			total += player.playCard(position);
			//play that value
		}
		else {
			//TODO: human interaction here
		}

		if (total > threshold) {
			//lose
		}
	}
}