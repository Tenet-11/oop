// 0515 HW1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (true) {
        getline(cin, s);
        if (s == "0") break;

        int len = 0;
        int i = s.length() - 1; //找最後單字長度

        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        cout << len << endl << endl;
    }
}

