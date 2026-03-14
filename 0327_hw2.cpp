// 0327 Hw2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (true) {
		cout << "Input a string or 0 to exit: ";
		cin >> s;
		if (s == "0") {
			break;
		}
		int count_P = 0, count_S = 0, count_B = 0; //P,S,B (小,中,大括號)
		
		int i = 0;
		int test_P = 0;
		while (s[i] != '\0') {
			if (s[i] == '(') count_P++;
			if (s[i] == ')') count_P--;
			if (s[i] == '[') count_S++;
			if (s[i] == ']') count_S--;
			if (s[i] == '{') count_B++;
			if (s[i] == '}') count_B--;

			if (count_P < 0) {
				test_P = 1;
			}

			i++;
		}
		count_P = abs(count_P);
		count_S = abs(count_S);
		count_B = abs(count_B);
		if (test_P == 1) count_P = 2;

		cout << "Parentheses: " << count_P << ", " << "Square Brackets: " << count_S << ", " << "Braces: " << count_B;
		cout << endl << endl;
	}
}


