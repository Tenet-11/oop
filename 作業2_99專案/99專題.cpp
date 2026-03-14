// 99專題.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "Player.h"
#include "Deck.h"
#include <iostream>
#include <iomanip> //為了setw排版用
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;



int suit_change(char suit) {
	if (suit == 'S') return 4;
	else if (suit == 'H') return 3;
	else if (suit == 'D') return 2;
	else return 1;
}

bool compare_cards(Player& p1, Player& p2) {
	pair<int, char> card1 = p1.get_decide_card();
	pair<int, char> card2 = p2.get_decide_card();

	if (card1.first != card2.first) {
		return card1.first > card2.first;
	}
	else {
		return suit_change(card1.second) > suit_change(card2.second);
	}
}

int main() {
	srand(time(0)); // 亂數初始化，只做一次！

	int people;
	cout << "請輸入玩家數量(2~5人): ";
	cin >> people;
	cout << endl;

	int round;
	cout << "請輸入要玩幾輪: ";
	cin >> round;
	cout << endl;

	// 建立 all_player（主容器）
	vector<Player> all_player;
	all_player.push_back(Player("助教", true));
	for (int i = 1; i < people; i++) {
		all_player.push_back(Player("電腦" + to_string(i), false));
	}
	
	Deck deck;
	vector<int> scores(all_player.size(), 0);
	for (int j = round; j > 0; j--) {

		// 每輪開始，清空狀態
		deck.reset(); // 洗牌
		for (auto& player : all_player) {
			player.reset_status(); // 清手牌、還原還在場上狀態、清決定牌
		}

		// 清除上一輪紀錄的東西
		vector<Player*> ranking;
		vector<Player*> eliminated;
		ranking.clear();
		eliminated.clear();

		int current_points = 0;
		bool reverse = false;
		int turn = 0;
		bool round_over = false;

		for (auto& player : all_player) {
			player.reset_status();
		}

		// 每位玩家抽牌決定出牌順序
		for (auto& player : all_player) {
			player.set_decide_card(deck.deal_card());
		}

		// 排序出牌順序
		sort(all_player.begin(), all_player.end(), compare_cards);

		cout << "出牌順序依序為: " << endl;
		int decide_index = 1;
		for (auto& player : all_player) {
			pair<int, char> decide_card = player.get_decide_card();
			cout << player.get_name() << "為第" << decide_index << "位出牌，因為他抽到 [" << decide_card.first << decide_card.second << "]" << endl;
			decide_index++;
		}

		// 發正式手牌（給 all_player）
		for (int i = 0; i < 5; i++) {
			for (auto& player : all_player) {
				player.receive_card(deck.deal_card());
			}
		}

		// 顯示所有人的手牌
		for (auto& player : all_player) {
			player.show_hand();
		}


		while (!round_over) {
			Player& current_player = all_player[turn];

			if (!current_player.still_playing()) {
				turn = (turn + 1) % all_player.size();
				continue;
			}
			cout << "\n目前總點數為：" << current_points << endl;
			cout << "輪到" << current_player.get_name() << "出牌。" << endl;

			// **檢查玩家是否爆掉**
			if (current_points > 99) {
				cout << current_player.get_name() << " 瀕臨爆炸，嘗試自救..." << endl;

				// 嘗試出牌來拯救自己
				pair<int, char> played = current_player.play_card(current_points);

				if (played.first == 1 && played.second == 'S') {
					current_points = 0;
				}
				else if (played.first == 5) {
					int target;
					if (current_player.is_human_player()) {
						for (int i = 0; i < all_player.size(); i++) {
							cout << i + 1 << ". " << all_player[i].get_name() << endl;
						}
						cout << "請輸入想要指定的玩家編號(注意不要輸入自己): ";
						cin >> target;
						turn = target - 1;
						current_player.receive_card(deck.deal_card());
						continue;
					}
					else {
						// 電腦隨機指定，不能選自己
						do {
							target = rand() % all_player.size();
						} while (target == turn);
						turn = target;
						current_player.receive_card(deck.deal_card());
						continue;
					}
				}
				else if (played.first == 10) {
					if (current_points > 89) current_points -= 10;
					else current_points += 10;
				}
				else if (played.first == 11) {
					if (!reverse) {
						turn = (turn + 1) % all_player.size();
					}
					else {
						turn = (turn - 1 + all_player.size()) % all_player.size();
					}
					current_player.receive_card(deck.deal_card());
					continue;
				}
				else if (played.first == 12) {
					if (current_points > 79) current_points -= 20;
					else current_points += 20;
				}
				else {
					cout << current_player.get_name() << " 沒有辦法拯救自己，爆掉了!" << endl;
					current_player.eliminate();
					eliminated.push_back(&current_player);

					int active_players = 0;
					Player* last_player = nullptr;
					for (auto& player : all_player) {
						if (player.still_playing()) {
							active_players++;
							last_player = &player;
						}
					}

					if (active_players == 0) {
						cout << "所有玩家都爆掉了！開始結算排名..." << endl;
						round_over = true;
						break;
					}

					if (active_players == 1) {
						ranking.push_back(last_player);
						round_over = true;
						break;
					}

					// **更新遊戲輪次**
					if (!reverse) {
						turn = (turn + 1) % all_player.size();
					}
					else {
						turn = (turn - 1 + all_player.size()) % all_player.size();
					}
					continue;
				}

				// 再次確認是否還是 >99，若是就爆掉
				if (current_points > 99) {
					cout << current_player.get_name() << " 爆掉了!" << endl;
					current_player.eliminate();
					eliminated.push_back(&current_player);


					if (!reverse) {
						turn = (turn + 1) % all_player.size();
					}
					else {
						turn = (turn - 1 + all_player.size()) % all_player.size();
					}
					continue;
				}
			}


			// 正常情況下的出牌流程
			pair<int, char> played = current_player.play_card(current_points);

			if (played.first == 1 && played.second == 'S') {
				current_points = 0;
			}
			else if (played.first == 4 && people == 4) {
				reverse = !reverse;
			}
			else if (played.first == 5) {
				int target;
				if (current_player.is_human_player()) {
					for (int i = 0; i < all_player.size(); i++) {
						cout << i + 1 << ". " << all_player[i].get_name() << endl;
					}
					cout << "請輸入想要指定的玩家編號(注意不要輸入自己): ";
					cin >> target;
					turn = target - 1;
					current_player.receive_card(deck.deal_card());
					continue;

				}
				else {
					// 電腦隨機指定
					// 強制不能選自己
					do {
						target = rand() % all_player.size();
					} while (target == turn);
					turn = target;
					current_player.receive_card(deck.deal_card());
					continue;
				}
			}
			else if (played.first == 10) {
				if (current_points > 89) {
					current_points -= 10;
				}
				else current_points += 10;
			}
			else if (played.first == 11) {
				if (!reverse) {
					turn = (turn + 1) % all_player.size();
				}
				else {
					turn = (turn - 1 + all_player.size()) % all_player.size();
				}
				current_player.receive_card(deck.deal_card());
				continue;
			}
			else if (played.first == 12) {
				if (current_points > 79) {
					current_points -= 20;
				}
				else current_points += 20;
			}
			else if (played.first == 13) {
				current_points = 99;
			}
			else current_points += played.first;

			// 指針的方向
			if (!reverse) {
				turn = (turn + 1) % all_player.size();
			}
			else {
				turn = (turn - 1 + all_player.size()) % all_player.size();
			}

			// 檢查這位玩家是否出完手牌
			if (current_player.get_hand_size() == 0) {
				cout << current_player.get_name() << "出完所有手牌!" << endl;
				current_player.eliminate();
				ranking.push_back(&current_player);// 紀錄玩家出完手牌的順序
			}
			else {
				current_player.receive_card(deck.deal_card());
			}

			cout << "更新後點數為：" << current_points << endl;
			if (current_points > 99) {
				cout << current_player.get_name() << "爆掉了!" << endl;
				current_player.eliminate();
				eliminated.push_back(&current_player);// 紀錄爆掉的順序
			}

			int active_players = 0;
			Player* last_player = nullptr;
			for (auto& player : all_player) {
				if (player.still_playing()) {
					active_players++;
					last_player = &player;
				}
			}
			if (active_players <= 1) {
				if (last_player) {
					ranking.push_back(last_player);
				}
				round_over = true;
			}
		}
		// === 每輪結束後計分 ===
		// 這是手牌出完的
		int score = all_player.size();
		for (int i = ranking.size() - 1; i >= 0; i--) {
			Player* p = ranking[i];
			p->add_score(score--);
		}
		
		// 這是爆掉的
		for (int i = eliminated.size() - 1; i >= 0; i--) {
			Player* p = eliminated[i];
			p->add_score(score--);
		}

		
		cout << "\n--- 第 " << (round - j + 1) << " 輪結束，目前總分統計 ---" << endl;
		for (size_t i = 0; i < all_player.size(); i++) {
			cout << setw(10) << left << all_player[i].get_name()
				<< " 分數：" << all_player[i].get_score() << endl;
		}
		cout << "----------------------------------------\n" << endl;
	}

}

// 相隔一個禮拜再次處理，目標3小時內搞定交上去
