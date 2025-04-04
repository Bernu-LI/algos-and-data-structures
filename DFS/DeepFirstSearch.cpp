#include <iostream>
#include <vector>

void dfs(std::vector <std::vector <int>>& graph, int v, std::vector <int>& visited) {
    visited[v] = 1;
    std::cout << v << " ";
    for (int to : graph[v]) {
        if (!visited[to]) {
            dfs(graph, to, visited);
        }
    }
}


int main() {
    std::vector <std::vector <int>> graph = { {4},
                                              {2, 4},
                                              {1, 5},
                                              {},
                                              {0, 1, 5, 6},
                                              {2, 4, 7},
                                              {4, 7},
                                              {5, 6} };
    std::vector <int> visited(graph.size(), 0);                                          
    for (int v = 0; v < graph.size(); v++) {
        if (!visited[v]) {
            dfs(graph, v, visited);
        }
    }
    return 0;
}