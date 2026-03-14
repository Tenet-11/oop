// deck.cpp
#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

Deck::Deck() {
	initialize_deck();
}

void Deck::initialize_deck() {
	cards.clear();
	char suits[] = { 'S', 'H', 'C', 'D' };
	for (int i = 1; i <= 13; i++) {
		for (char suit : suits) {
			cards.push_back({ i, suit });
		}
	}
	random_shuffle(cards.begin(), cards.end());
}

void Deck::reset() {
	cards.clear();
	initialize_deck();
}

pair<int, char> Deck::deal_card() {
	if (cards.empty()) {
		cout << "沒牌可以給玩家抽了!";
		return{ -1,'X' };
	}
	pair<int, char> card = cards.back();
	cards.pop_back();
	return card;
}
