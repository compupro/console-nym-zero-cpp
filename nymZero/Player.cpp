#include "stdafx.h"
#include "Player.h"
#include <vector>
#include <stdexcept>
#include <string>

Player::Player(double startingBalance) {
	balance = startingBalance;
}

void Player::addToHand(int card) {
	hand.push_back(card);
}

int Player::playCard(int value) {
	std::vector<int>::iterator cardLocation = std::find(hand.begin(), hand.end(), value);
	if ( cardLocation ==  hand.end() ) { //if value not in hand
		throw std::range_error("No card of value in hand");
	}
	else {
		hand.erase(cardLocation);
	}
	return value;
}

std::string Player::getHandString() {
	std::string handString = "";
	for (int card : hand) {
		handString = handString + " " + std::to_string(card);
	}
	return handString;
}

double Player::bet(double bet) {
	if ( bet > balance ) {
		throw std::out_of_range("Player lacks required balance to bet this amount");
	}
	else {
		balance -= bet;
	}
	return bet;
}

void Player::increaseBalance(double amount) {
	balance += amount;
}

std::string Player::getBalanceString() {
	std::string balString = "$";
	return balString + std::to_string(balance);
}