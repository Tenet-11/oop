// 0313 hw2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


#include <iostream>
#include "time.h"
using namespace std;

/*
class Time {
private:
	int hour, minute, second;
public:
	// 定義建構子
	// 這裡建構子的參數是用來接收外部傳入的訊息
	Time() :hour(0), minute(0), second(0){}

	//建構子?
	Time(int h, int m, int s) {
		setTime(h, m, s);
	}

	// 輸入type_1
	void setTime(int h,int m,int s) {
		if (h < 0 || h >= 24 || m < 0 || m >= 60 || s < 0 || s >= 60) {
			cout << "Error!" << endl;
			cout << "\n";
			return;
		}
		hour = h;
		minute = m;
		second = s;
	}

	//輸入type_2
	// Ps:這運用到多型的概念
	void setTime(int totalseconds) {
		if (totalseconds < 0 || totalseconds > 86400) {
			cout << "Error!" << endl;
			cout << "\n";
			return;
		}
		hour = (totalseconds / 3600) % 24;
		minute = (totalseconds / 60) % 60;
		second = totalseconds % 60;
	}

	// 24小時制轉12小時制
	void showTime() {
		string period = (hour >= 12) ? "PM" : "AM";
		int displayHour = (hour % 12 == 0) ? 12 : hour % 12;
		printf("Set time: %02d:%02d:%02d %s\n", displayHour, minute, second, period.c_str());
	}
};*/

int main()
{
	cout << "Initial Time is: 00:00:00 AM" << endl << endl;
	int hour, minute, second;
	Time time;
	
	while (true) {
		cout << "Please set time: ";
		cin >> hour;
		if (hour == -1) break;

		// peek會查看下一個輸入字元
		// 總秒數的輸入方法
		if (cin.peek() == '\n') {
			time.setTime(hour);
			if (hour > 86400) {
				continue;
			}
			else {
				time.showTime();
				cout << "\n";
			}
		}
		else {
			cin >> minute >> second;
			time.setTime(hour, minute, second);
			if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60 || second < 0 || second >= 60) {
				continue;
			}
			else {
				time.showTime();
				cout << "\n";
			}
		}
	}
}