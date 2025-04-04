#include <iostream>
#include <vector>

using namespace std;

vector <int> getPath(vector <int>& from, int finish) {
    vector <int> path;
    for (int v = finish; v != -1; v = from[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

void topologicalSort(vector <vector <pair <int, int>>>& graph, int v, vector <int>& visited, vector <int>& order) {
    visited[v] = 1;
    for (auto& [to, weight] : graph[v]) {
        if (!visited[to]) {
            topologicalSort(graph, to, visited, order);
        }
    }
    order.push_back(v);
}

pair <vector <int>, vector <int>> topSortShortestPath(vector <vector <pair <int, int>>>& graph, int start) {
    vector <int> visited(graph.size(), 0);
    vector <int> order;
    for (int v = 0; v < graph.size(); v++) {
        if (!visited[v]) {
            topologicalSort(graph, v, visited, order);
        }
    }
    reverse(order.begin(), order.end());
    vector <int> dist(graph.size(), INT_MAX);
    dist[start] = 0;
    vector <int> from(graph.size(), -1);
    for (int v : order) {
        for (const auto& [to, weight] : graph[v]) {
            if (dist[v] != INT_MAX and dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;
                from[to] = v;
            }
        }
    }
    return {dist, from};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }
    int start;
    cin >> start;
    auto [dist, from] = topSortShortestPath(graph, start);
    for (int d : dist) {
        if (d != INT_MAX) {
            cout << d << " ";
        }
        else {
            cout << "X ";
        }
    }
    cout << "\n";
    for (int v : getPath(from, 7)) {
        cout << v << " ";
    }
    return 0;
}