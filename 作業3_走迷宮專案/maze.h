#pragma once
#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;

class Maze {
public:
    int N, M;
    vector<string> grid;
    vector<string> origGrid;
    vector<vector<bool>> visited;
    vector<pair<int, int>> path;

    int dr[4] = { -1,0,1,0 };
    int dc[4] = { 0,1,0,-1 };

    void loadmap(const string& filename);
    bool dfs(int r, int c);
    void print();
    void animate(int delay_ms);
    void manual_play();
    void auto_play();
};

#endif