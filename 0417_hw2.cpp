// 0417 hw2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;

int main()
{
	Stack s;
	int N;
	cout << "Enter a number (1~52): ";
	cin >> N;

	string card;
	for (int i = 0; i < N; i++) {
		cin >> card;
		s.input(card);
	}
	while (1) {
		cout << endl <<
			"1.Deal one card" << endl <<
			"2.Shuffle the cards" << endl <<
			"3.Exit" << endl << ": ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:s.pop(); break;
		case 2:s.shuffle(); break;
		case 3: return 0;
		}
	}
}

