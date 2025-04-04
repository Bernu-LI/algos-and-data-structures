#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int bfs(vector <string>& graph, vector <pair <int, int>>& startCells, vector <pair <int, int>>& finishCells) {
    int h = graph.size(), w = graph[0].size();
    vector <vector <int>> dist(h, vector <int>(w, INT_MAX));
    vector <vector <pair <int, int>>> from(h, vector <pair <int, int>>(w, {-1, -1}));
    queue <pair <int, int>> q;
    for (auto& [startY, startX] : startCells) {
        dist[startY][startX] = 0;
        q.push({startY, startX});
    }
    vector <int> dy = {1, 0, -1, 0};
    vector <int> dx = {0, 1, 0, -1};
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (ty >= 0 and ty < h and tx >= 0 and tx < w and
                dist[ty][tx] == INT_MAX and graph[ty][tx] != '#') {
                dist[ty][tx] = dist[y][x] + 1;
                from[ty][tx] = {y, x};
                q.push({ty, tx});
            }
        }
    }
    auto [finishY, finishX] = finishCells[0];
    for (auto& [y, x] : finishCells) {
        if (dist[finishY][finishX] > dist[y][x]) {
            finishY = y;
            finishX = x;
        }
    }
    if (dist[finishY][finishX] != INT_MAX) {
        int y = finishY;
        int x = finishX;
        while (y != -1 and x != -1) {
            graph[y][x] = '*';
            auto [py, px] = from[y][x];
            y = py;
            x = px;
        }
    }
    return dist[finishY][finishX];
}

int main() {
    vector <string> graph = { {"...#......"},
                              {".F....#..."},
                              {"...#######"},
                              {".........F"},
                              {"#######.##"},
                              {".....#...."},
                              {".S.#.#...."},
                              {"...#......"} };
    vector <pair <int, int>> startCells = { {6, 1}, {7, 9} };
    vector <pair <int, int>> finishCells = { {1, 1}, {3, 9} };
    int stepQuantity = bfs(graph, startCells, finishCells);
    if (stepQuantity != INT_MAX) {
        cout << stepQuantity << "\n";
        for (const string& row : graph) {
            cout << row << "\n";
        }
    }
    else {
        cout << "Impossible";
    }
    return 0;
}