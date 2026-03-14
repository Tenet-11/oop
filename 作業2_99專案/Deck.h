#pragma once
// deck.h
#ifndef DECK_H
#define DECK_H

#include <vector>
using namespace std;

class Deck {
private:
	vector<pair<int, char>> cards;

public:
	Deck();
	void initialize_deck();
	void reset();
	pair<int, char> deal_card();
};

#endif