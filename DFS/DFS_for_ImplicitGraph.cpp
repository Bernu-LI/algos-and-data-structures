#include <vector>
#include <string>
#include <iostream>

void dfs(std::vector <std::string>& graph, int y, int x, int component) {
    graph[y][x] = 'A' + component - 1;
    std::vector <int> dy = {-1, 0, 1, 0};
    std::vector <int> dx = {0, -1, 0, 1};
    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];
        if (ty >= 0 and ty < graph.size() and tx >= 0 and tx < graph[ty].size() and graph[ty][tx] == '#') {
            dfs(graph, ty, tx, component);
        }
    }
}

int main() {
    std::vector <std::string> graph = {".##..##.",
                                       "....###",
                                       ".##..#..",
                                       "..##....",
                                       "#....##.",
                                       ".....##.",
                                       ".##.....",
                                       "...##..."};
    int componentCounter = 0;
    for (int y = 0; y < graph.size(); y++) {
        for (int x = 0; x < graph[y].size(); x++) {
            if (graph[y][x] == '#') {
                componentCounter++;
                dfs(graph, y, x, componentCounter);
            }
        }
    }
    for (auto& row : graph) {
        std::cout << row << "\n";
    }
    std::cout << componentCounter;
    return 0;
}