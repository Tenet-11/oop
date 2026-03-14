// 0424 Hw1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;

int main()
{
    while (1)
    {
        int hour, minute;
        cin >> hour;
        if (hour == -1) break;
        cin >> minute;

        float degree_m = minute * 6;
        float degree_s = hour * 30 + minute * 0.5;

        float result = degree_m - degree_s;
        if (result > 180) {
            result = 360 - result;
        }
        if (result<0 && result>-180) {
            result = -result;
        }
        if (result < -180) {
            result = 360 + result;
        }
        int int_result = (int)(result + 0.5);
        cout << int_result << endl;
    }

}

