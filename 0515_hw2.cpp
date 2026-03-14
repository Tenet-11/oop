// 0515 HW2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> //為了sort
using namespace std;

int main()
{
	ifstream text("text.txt");
	ofstream output("output.txt");
	vector <int> num;
	string s, temp, all;

	while (getline(text, s)) {
		all += s + ' ';
	}
	for (char c : all) {
		if (c >= '0' && c <= '9') {
			temp += c;
		}
		else {
			// 非數字時檢查temp是否有內容
			if (!temp.empty()) {
				num.push_back(stoi(temp));  // stoi是把字串轉成整數
				temp.clear();
			}
		}
	}
	// 放止字串最後面是數字沒放進去
	if (!temp.empty()) {
		num.push_back(stoi(temp));  // stoi是把字串轉成整數
		temp.clear();
	}

	sort(num.begin(), num.end());

	for (int n : num) {
		cout << n << " ";
		output << n << " ";
	}
	cout << endl << endl;

	text.close();
	output.close();
}


