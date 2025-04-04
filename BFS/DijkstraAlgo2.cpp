#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <int> getPath(vector <int> from, int finish) {
    vector <int> path;
    for (int v = finish; v != -1; v = from[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

pair <vector <int>, vector <int>> dijkstra(vector <vector <pair <int, int>>>& graph, int start) {
    vector <int> dist(graph.size(), INT_MAX);
    dist[start] = 0;
    vector <int> from(graph.size(), -1);
    set <pair <int, int>> unvisitedVertices;
    unvisitedVertices.insert({dist[start], start});
    while (!unvisitedVertices.empty()) {
        int nearest = unvisitedVertices.begin()->second;
        unvisitedVertices.erase(unvisitedVertices.begin()); 
        for (auto [to, weight] : graph[nearest]) {
            if (dist[to] > dist[nearest] + weight) {
                unvisitedVertices.erase({dist[to], to});
                dist[to] = dist[nearest] + weight;
                from[to] = nearest;
                unvisitedVertices.insert({dist[to], to});
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
        graph[to].push_back({from, weight});
    }
    int start;
    cin >> start;
    auto [dist, from] = dijkstra(graph, start);
    for (int d : dist) {
        if (d != INT_MAX) {
            cout << d << " ";
        }
        else {
            cout << "X ";
        }
    }
    cout << "\n";
    for (int v : getPath(from, 5)) {
        cout << v << " ";
    }
    return 0;
}