// 倉庫番 專案.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <fstream>
#include "Windows.h"
#include "maze.h"

using namespace std;

class Sokoban :public Maze {
public:
	void manual_play() {
		//找起點
		int r = -1, c = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (grid[i][j] == '0') {
					r = i;
					c = j;
				}
			}
		}

		char direction;
		int count = 0;
		bool found = false;
		while (true) {
			system("cls");
			print();
			cin >> direction;
			count++;
			int dir_idx = -1;
			if (direction == 'w') dir_idx = 0;
			else if (direction == 'd')dir_idx = 1;
			else if (direction == 's')dir_idx = 2;
			else if (direction == 'a')dir_idx = 3;
			else {
				cout << "請重新輸入方向\n";
				continue;
			}

			// 檢查周圍有無箱子 (遇到箱子情況)
			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (grid[nr][nc] == '1') {
					found = true;
					break;
				}
			}
			if (found == true) {
				int nr = -1, nc = -1;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (grid[i][j] == '1') {
							nr = i, nc = j;
						}
					}
				}
				int nnr = nr + dr[dir_idx];
				int nnc = nc + dc[dir_idx];
				if (nnr < 0 || nnr >= N || nnc < 0 || nnc >= M) {
					cout << "箱子超出邊界了~\n";
					Sleep(3000);
					continue;
				}
				if (grid[nnr][nnc] == '/') {
					cout << "箱子撞到牆了~\n";
					Sleep(3000);
					continue;
				}
				if (grid[nnr][nnc] == '2') {
					cout << "恭喜抵達終點，遊戲結束。你總共花了" << count << "步抵達終點" << endl;
					break;
				}

				// 更新位置
				// 記得箱子的位置要後面再更正
				grid[r][c] = '-';
				grid[nnr][nnc] = '1';
				grid[nr][nc] = '0';
				r = nr, c = nc;

				// 判定是否為死角
				bool check = blind_spot(nnr, nnc);
				if (check == true) {
					cout << "你不小心走到死角了，遊戲結束。\n";
					break;
				}
				continue;
			}




			// 玩家下一格位置 (沒遇到箱子情況)
			int nr = r + dr[dir_idx];
			int nc = c + dc[dir_idx];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
				cout << "超出邊界了~\n";
				Sleep(3000);
				continue;
			}
			if (grid[nr][nc] == '/') {
				cout << "撞到牆了~\n";
				Sleep(3000);
				continue;
			}

			grid[nr][nc] = '0';
			grid[r][c] = '-';
			r = nr;
			c = nc;
		}
	}

	bool blind_spot(int r, int c) {

		// 死角跟終點衝突
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (grid[nr][nc] == '2') return false;
		}

		// 第一種死角情況
		int check = 0;
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if ((grid[nr][nc] == '/' )|| (grid[nr][nc] == '0')) {
				check++;
			}
		}
		if (check == 4) return true;
		
		// 第二種死角情況
		int i = -1, j = -1;
		if (check == 3) {
			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (grid[nr][nc] == '-') {
					i = nr;
					j = nc;
					break;
				}
			}
			if (i - 2 >= 0 && i-2 < N && j >= 0 && j < M) {
				if (grid[i - 2][j] == '0')return false;
			}
			if (i + 2 >= 0 && i+2 < N && j >= 0 && j < M) {
				if (grid[i + 2][j] == '0')return false;
			}
			if (i>= 0 && i < N && j-2 >= 0 && j-2 < M) {
				if (grid[i][j-2] == '0')return false;
			}
			if (i  >= 0 && i < N && j+2 >= 0 && j+2 < M) {
				if (grid[i][j+2] == '0')return false;
			}

			return true;
		}
	}
};


int main()
{
	Sokoban sokoban;
	string filename;
	cout << "Enter a filename,remember to enter.txt\n";
	cin >> filename;
	sokoban.loadmap(filename);
	cout << "運作方式 : \n" << "玩家輸入移動方向(w,a,s,d)\n" << "( 請輸入1進入遊戲 )\n\n";
	int choice;
	cin >> choice;
	if (choice == 1) {
		sokoban.manual_play();
	}
	else {
		cout << "輸入錯誤，請重新輸入";
	}
}

