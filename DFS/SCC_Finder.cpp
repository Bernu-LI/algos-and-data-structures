#include <vector>
#include <algorithm>
#include <iostream>

class Graph {
    const std::vector <std::vector <int>>& graph;
    std::vector <std::vector <int>> reversedGraph;

    std::vector <int> visited;
    std::vector <int> order;

    void topologicalSort(int v) {
        visited[v] = 1;
        for (int to : reversedGraph[v]) {
            if (!visited[to]) {
                topologicalSort(to);
            }
        }
        order.push_back(v);
    }

    void colorize(int v, int component) {
        visited[v] = component;
        for (int to : graph[v]) {
            if (!visited[to]) {
                colorize(to, component);
            }
        }
    }

    public:
        Graph(const std::vector <std::vector <int>>& graph_): graph(graph_) {
            reversedGraph.resize(graph.size());
            for (int l = 0; l < graph.size(); l++) {
                for (int v : graph[l]) {
                    reversedGraph[v].push_back(l);
                }
            }
        }

        std::vector <int> findSCC() {
            visited.assign(graph.size(), 0);
            for (int v = 0; v < graph.size(); v++) {
                if (!visited[v]) {
                    topologicalSort(v);
                }
            }
            std::reverse(order.begin(), order.end());
            visited.assign(graph.size(), 0);
            int componentCounter = 0;
            for (int v : order) {
                if (!visited[v]) {
                    componentCounter++;
                    colorize(v, componentCounter);
                }
            }
            return visited;
        }
};

int main() {
    int v, e;
    std::cin >> v >> e;
    std::vector <std::vector <int>> graph(v);
    for (int i = 0; i < e; i++) {
        int from, to;
        std::cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }
    Graph g1(graph);
    std::vector <int> scc = g1.findSCC();
    for (int color : scc) {
        std::cout << color << " ";
    }
    return 0;
}