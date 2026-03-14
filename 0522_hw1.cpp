// 0522 HW1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>

using namespace std;
int main()
{
    while (1) {
        string s;
        cin >> s;
        if (s == "0") break;
        int count = 0, i = 0;
        while (s[i] != '\0') {
            count++;
            i++;
        }
        for (int j = count; j >= 0; j--) {
            cout << s[j];
        }
        cout << "\n\n";
    }
}


