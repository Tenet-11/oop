#pragma once
// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
using namespace std;

class Player {
private:
	string name;
	bool is_human;
	bool is_active;
	int total_score;
	vector<pair<int, char>> hand;
	vector<pair<int, char>> decide_hand;

public:
	Player(string player_name, bool human);

	bool is_human_player();
	int get_hand_size();
	string get_name();
	void set_decide_card(pair<int, char> card);
	pair<int, char> get_decide_card();
	void receive_card(pair<int, char> card);
	bool still_playing();
	void eliminate();
	void add_score(int);
	int get_score()const;
	void reset_status();
	void show_hand();
	pair<int, char> play_card(int current_points);
};

#endif