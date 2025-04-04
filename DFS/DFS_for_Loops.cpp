#include <vector>
#include <iostream>
#include <algorithm>

std::vector <int> getLoop(std::vector <int>& from, int lastVertex) {
    std::vector <int> loop;
    for (int v = from[lastVertex]; v != lastVertex; v = from[v]) {
        loop.push_back(v);
    }
    loop.push_back(lastVertex);
    std::reverse(loop.begin(), loop.end());
    return loop;
}

void dfs(std::vector <std::vector <int>>& graph, int v, std::vector <int>& visited, std::vector <int>& from, std::vector <int>& loop) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (visited[to] == 0) {
            from[to] = v;
            dfs(graph, to, visited, from, loop);
            if (!loop.empty()) {
                return;
            }
        }
        else  if (visited[to] == 1) {
            from[to] = v;
            loop = getLoop(from, to);
            return;
        }
    }
    visited[v] = 2;  
}

int main() {
    std::vector <std::vector <int>> graph = { {4},
                                              {4},
                                              {1},
                                              {},
                                              {1, 6},
                                              {2},
                                              {7},
                                              {5} };
    std::vector <int> visited(graph.size(), 0);
    std::vector <int> from (graph.size(), -1);
    std::vector <int> loop;
    for (int v = 0; v < graph.size() and loop.empty(); v++) {
        if(!visited[v]) {
            dfs(graph, v, visited, from, loop);
        }
    }
    if (!loop.empty()) {
        std::cout << "YES\n";
        for (int v : loop) {
            std::cout << v + 1 << " "; 
        }
    }
    else {
        std::cout << "NO";
    }
    return 0;
}