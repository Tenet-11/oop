// player.cpp
#include "Player.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Player::Player(string player_name, bool human) {
	name = player_name;
	is_human = human;
	is_active = true;
	total_score = 0;
}

bool Player::is_human_player() {
	return is_human;
}

int Player::get_hand_size() {
	return hand.size();
}

string Player::get_name() {
	return name;
}


void Player::set_decide_card(pair<int, char> card) {
	decide_hand.clear();
	decide_hand.push_back(card);
}

pair<int, char> Player::get_decide_card() {
	return decide_hand.front();
}

void Player::receive_card(pair<int, char> card) {
	if (hand.size() < 5) {
		hand.push_back(card);
	}
}

bool Player::still_playing() {
	return is_active;
}

void Player::eliminate() {
	is_active = false;
}

void Player::add_score(int s) {
	total_score += s;
}

int Player::get_score()const {
	return total_score;
}

void Player::reset_status() {
	is_active = true;
	hand.clear();
	decide_hand.clear();
}

void Player::show_hand() {
	cout << name << "的手牌為: ";
	for (auto card : hand) {
		cout << " [" << card.first << card.second << "] ";
	}
	cout << endl;
}

pair<int, char> Player::play_card(int current_points) {
	pair<int, char> chosen_card;

	if (is_human) {
		cout << name << "的手牌為:" << endl;
		for (int i = 0; i < hand.size(); i++) {
			cout << i + 1 << ". [" << hand[i].first << hand[i].second << "]" << endl;
		}

		int choice;
		while (true) {
			cout << "請選擇要出的牌（輸入 1～" << hand.size() << "的數字）: ";
			cin >> choice;
			if (choice >= 1 && choice <= hand.size()) {
				chosen_card = hand[choice - 1];
				hand.erase(hand.begin() + (choice - 1));
				break;
			}
			else {
				cout << "輸入錯誤，請重新輸入。" << endl;
			}
		}
	}
	else {
		int index = rand() % hand.size();
		chosen_card = hand[index];
		cout << name << "出了 [" << chosen_card.first << chosen_card.second << "]" << endl;
		hand.erase(hand.begin() + index);
	}

	return chosen_card;
}