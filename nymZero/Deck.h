#pragma once
#include <vector>
#include <chrono>

class Deck {
private:
	std::vector<int> contents;
	double balance;
public:
	Deck(
		int maxValue,
		int copies,
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count()
	);
	int draw();
};