// 走迷宮.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Windows.h"
#include "maze.h"

using namespace std;

int main() {
    Maze maze;
    int mode;
    string filename;
    cout << "請輸入要讀取的地圖檔名 (記得包含檔案型別   Ex .txt等): " << endl;
    cin >> filename;
    maze.loadmap(filename);

    cout << endl << endl;
    cout << "請選擇模式: " << endl << endl << "1.使用者自己走迷宮 (利用w,a,s,d)方向鍵" << endl << "2.電腦幫你自動走" << endl;
    cin >> mode;
    cout << "\n\n";
    if (mode == 1) {
        maze.manual_play();
    }
    else {
        maze.auto_play();
    }
    return 0;
}

