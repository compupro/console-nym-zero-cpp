#include "stdafx.h"
#include "Game.h"
#include "Deck.h"
#include "Player.h"
#include <vector>

Game::Game(int numPlayers, int startingBalance, int maxCardValue, int cardCopies, int handSize, int threshold) {
	this->threshold = threshold; //TODO: heresy?
	deck = new Deck(maxCardValue, cardCopies);
	for (int p = 0; p < numPlayers - 1; p++) {
		players.push_back(Player(startingBalance, false));
		drawCardsTo(players.back(), handSize);
	}
	players.push_back(Player(startingBalance, true));
	drawCardsTo(players.back(), handSize);
}

void Game::drawCardsTo(Player player, int numCards) {
	for (int c = 0; c < numCards; c++) {
		player.addToHand(deck->draw());
	}
}