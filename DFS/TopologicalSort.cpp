#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

void dfs(std::vector <std::vector <int>>& graph, int v, std::vector <int>& visited, std::vector <int>& order) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to]) {
            dfs(graph, to, visited, order);
        }
    }
    order.push_back(v);
}

int main() {
    std::vector <std::vector <int>> graph = { {2, 4},
                                              {},
                                              {1},
                                              {},
                                              {1, 2, 5},
                                              {},
                                              {5} };
    std::vector <std::string> vertexNames = {"shirt", "coat", "blazer", "glasses", "pants", "shoes", "socks"};
    std::vector <int> visited (graph.size(), 0);
    std::vector <int> order;
    for (int v = 0; v < graph.size(); v++) {
        if (!visited[v]) {
            dfs(graph, v, visited, order);
        }
    }
    std::reverse(order.begin(), order.end());
    for (int i : order) {
        std::cout << vertexNames[i] << "\n";
    }
    return 0;
}