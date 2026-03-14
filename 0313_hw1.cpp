// 0313 hw1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
using namespace std;


int check(string str) {
    if (str.length() == 10 &&
        (str[1] == '1' || str[1] == '2') && //記得數字1,2是字元
        (str[0] >= 'A' && str[0] <= 'Z')) {
        return 1;
    }
    else return 0;
}

int main()
{
    cout << "Please Enter an ID Number:";
    string str;
    cin >> str;

    int answer = check(str);
    if (answer == 1) cout << "Correct" << endl;
    else cout << "Incorrect" << endl;
}


