// 21點 專案.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Deck {
private:
    vector<int> cards;
public:
    Deck() {
        initialize();
    }
    void initialize() {
        vector<int> deck = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
        cards.clear();
        for (int i = 0; i < 4; i++) {
            cards.insert(cards.end(), deck.begin(), deck.end());
        }
        random_shuffle(cards.begin(), cards.end());
    }
    int deal_card() {
        int card = cards.back();
        cards.pop_back();
        return card;
    }
};

class Player {
protected:
    vector<int> hand;
public:
    void receive_card(int card) {
        hand.push_back(card);
    }
    int calculate_points() {
        int total_points = 0;
        int ace_count = 0;
        for (int card : hand) {
            total_points += card;
            if (card == 11) ace_count++;
        }
        while (total_points > 21 && ace_count > 0) {
            total_points -= 10;
            ace_count--;
        }
        return total_points;
    }
    void show_hand() {
        for (int card : hand) cout << card << " ";
        cout << "(共 " << calculate_points() << " 點)" << endl;
    }
    vector<int> get_hand() { return hand; }
};

class Dealer : public Player {
public:
    void show_first_card() {
        cout << "莊家的明牌: " << hand[1] << endl;
    }
};

class BlackjackGame {
private:
    Deck deck;
    Player user;
    Dealer dealer;
public:
    void play() {
        deck.initialize();
        user = Player();
        dealer = Dealer();

        user.receive_card(deck.deal_card());
        dealer.receive_card(deck.deal_card());
        user.receive_card(deck.deal_card());
        dealer.receive_card(deck.deal_card());

        cout << "玩家的牌: ";
        user.show_hand();
        dealer.show_first_card();

        char choice;
        while (true) {
            cout << "輸入 y 加牌、輸入 n 看結果: ";
            cin >> choice;
            if (choice == 'y') {
                user.receive_card(deck.deal_card());
                cout << "玩家的牌: ";
                user.show_hand();
                if (user.calculate_points() > 21) break;
            }
            else if (choice == 'n') {
                break;
            }
            else {
                cout << "請重新輸入!" << endl;
            }
        }

        while (dealer.calculate_points() < 17) {
            dealer.receive_card(deck.deal_card());
        }

        cout << "玩家的牌: ";
        user.show_hand();
        cout << "莊家的牌: ";
        dealer.show_hand();

        int user_points = user.calculate_points();
        int dealer_points = dealer.calculate_points();

        if (user_points > 21) {
            cout << "你輸了!" << endl;
        }
        else if (dealer_points > 21 || user_points > dealer_points) {
            cout << "你贏了!" << endl;
        }
        else if (user_points == dealer_points) {
            cout << "平手!" << endl;
        }
        else {
            cout << "你輸了!" << endl;
        }
    }
};

int main() {
    srand(time(0));
    BlackjackGame game;
    cout << "歡迎來到21點遊戲！" << endl;
    game.play();

    while (true) {
        char user_input;
        cout << "=======================================" << endl;
        cout << "重新進行遊戲？請輸入 y 開始、輸入 n 結束: ";
        cin >> user_input;
        if (user_input == 'y') {
            game.play();
        }
        else if (user_input == 'n') {
            cout << "Bye~" << endl;
            break;
        }
    }
    return 0;
}

