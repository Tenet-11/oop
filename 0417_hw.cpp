// 0417 HW.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <sstream>
#include "stack.h"
using namespace std;

int main()
{
    Stack s;
    string line;
    int value;
    
    // stringstream的語法學習
    getline(cin, line);
    stringstream ss(line);

    int count = 0;
    while (ss >> value && count < 10) {
        s.input(value);
        count++;
    }

    while (1) {
        cout << endl << "1.push" << endl << "2.pop" << endl << "3.empty" << endl << "4.top" << endl << "5.結束測試" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            s.push(); 
            continue;
        case 2:
            s.pop();
            continue;
        case 3:
            s.empty();
            continue;
        case 4:
            s.top();
            continue;
        default:
            return 0;
        }

    }
}

 
/*
int N;
cout << "請輸入要輸入的數字個數(1~10): ";
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> value;
        s.input(value);
    }*/