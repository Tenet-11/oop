// 0424 Hw2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> Vincent_f;
	vector<string> Leo_f;
	vector<string> Invitee;

	string name;

	//輸入Vincent 朋友
	cout << "#Vincent's friends: " << endl;
	while (1) {
		cin >> name;
		if (name == "0") {
			cout << endl;
			break;
		}
		Vincent_f.push_back(name);
	}

	//輸入Leo 朋友
	cout << "#Leo's friends: " << endl;
	while (1) {
		cin >> name;
		if (name == "0") {
			cout << endl;
			break;
		}
		Leo_f.push_back(name);
	}

	//合併
	for (string n : Vincent_f) {
		Invitee.push_back(n);
	}
	for (string n : Leo_f) {
		if (find(Invitee.begin(), Invitee.end(), n) == Invitee.end()) {
			Invitee.push_back(n);
		}
	}

	cout << "# Invitee: " << endl;
	for (string n : Invitee) {
		cout << n << endl;
	}
}

