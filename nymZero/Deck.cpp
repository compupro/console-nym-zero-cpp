#include "stdafx.h"
#include "Deck.h"
#include <iostream>
#include <random>
#include <chrono>

Deck::Deck(int maxValue, int copies, unsigned seed) {
	
	for (int value = 0; value < maxValue + 1; value++) {
		for (int copy = 0; copy < copies; copy++) {
			contents.push_back(value);
		}
	}
	std::shuffle(contents.begin(), contents.end(), std::default_random_engine(seed));
}

int Deck::draw() {
	int value = contents.back();
	contents.pop_back();
	return value;
}
