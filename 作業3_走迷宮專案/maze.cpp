#include "Maze.h"

void Maze::loadmap(const string& filename) {
    ifstream file(filename);
    file >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; i++)
        file >> grid[i];
    file.close();

    origGrid = grid;
    visited.assign(N, vector<bool>(M, false));
}

bool Maze::dfs(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    if (grid[r][c] == '/') return false;
    if (visited[r][c]) return false;

    visited[r][c] = true;
    path.emplace_back(r, c);

    if (grid[r][c] == '1') {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (dfs(nr, nc))
            return true;
    }

    path.pop_back();
    return false;
}

void Maze::print() {
    for (auto& row : grid) {
        cout << row << "\n";
    }
    cout.flush();
}

void Maze::animate(int delay_ms) {
    for (auto& p : path) {
        grid = origGrid;
        grid[p.first][p.second] = '*';
        system("cls");
        print();
        Sleep(delay_ms);
    }
    grid = origGrid;
}

void Maze::manual_play() {
    int r = -1, c = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (origGrid[i][j] == '0') {
                r = i;
                c = j;
            }
        }
    }

    int pathCount = 0;
    grid = origGrid;
    grid[r][c] = '*';
    print();

    char direction;
    while (origGrid[r][c] != '1') {
        cin >> direction;
        pathCount++;
        int nr = r, nc = c;
        if (direction == 'w') nr = r - 1;
        else if (direction == 's') nr = r + 1;
        else if (direction == 'a') nc = c - 1;
        else if (direction == 'd') nc = c + 1;
        else continue;

        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
            cout << "超出邊界了! 請重新嘗試" << endl;
            continue;
        }
        if (origGrid[nr][nc] == '/') {
            cout << "撞到牆了! 請重新嘗試" << endl;
            continue;
        }

        grid[r][c] = origGrid[r][c];
        r = nr, c = nc;
        grid[r][c] = '*';

        system("cls");
        print();
    }
    cout << "恭喜走到終點!  你總共花了" << pathCount << "步抵達終點" << endl;
}

void Maze::auto_play() {
    int sr = -1, sc = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (origGrid[i][j] == '0') {
                sr = i;
                sc = j;
            }
        }
    }

    if (!dfs(sr, sc)) {
        cout << "此迷宮無解";
    }
    animate(300);
    cout << "抵達終點，步數 = " << path.size() - 1 << "\n";
}
