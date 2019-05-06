#include "stdafx.h"
#include "Game.h"
#include "Deck.h"
#include "Player.h"
#include <vector>
#include <random>

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
}

void Game::drawCardsTo(Player player, int numCards) {
	for (int c = 0; c < numCards; c++) {
		player.addToHand(deck->draw());
	}
}

void Game::playRound() {

}