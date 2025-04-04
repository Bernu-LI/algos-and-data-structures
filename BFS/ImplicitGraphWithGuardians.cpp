#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int bfs(vector <string>& graph, int startY, int startX, int finishY, int finishX) {
    int h = graph.size(), w = graph[0].size();
    vector <vector <int>> dist(h, vector <int>(w, INT_MAX));
    vector <vector <pair <int, int>>> from(h, vector <pair <int, int>>(w, {-1, -1}));
    deque <pair <int, int>> q;
    dist[startY][startX] = 0;
    q.push_back({startY, startX});
    vector <int> dy = {1, 0, -1, 0};
    vector <int> dx = {0, 1, 0, -1};
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop_front();
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (ty >= 0 and ty < h and dist[ty][tx] == INT_MAX) {
                if (graph[ty][tx] == 'G') {
                    dist[ty][tx] = dist[y][x] + 1;
                    from[ty][tx] = {y, x};
                    q.push_back({ty, tx});
                }
                else if (graph[ty][tx] != '#') {
                    dist[ty][tx] = dist[y][x];
                    from[ty][tx] = {y, x};
                    q.push_front({ty, tx});
                }
            }
        }
    }
    if (dist[finishY][finishX] != INT_MAX) {
        int y = finishY, x = finishX;
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
    vector <string> graph = { {"...#G....."},
                              {"...G..#.F."},
                              {"G.G#######"},
                              {".....G...F"},
                              {"#######G##"},
                              {".....#...."},
                              {".S.#.#GG.G"},
                              {"...#......"} };
    int startY = 6, startX = 1;
    int finishY = 1, finishX = 8;
    int stepCount = bfs(graph, startY, startX, finishY, finishX);
    if (stepCount != INT_MAX) {
        cout << stepCount << "\n";
        for (auto& row : graph) {
            cout << row << "\n";
        }
    }
    return 0;
}