#include <iostream>
#include <vector>

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
    vector <int> dist(graph.size(), 1e9);
    dist[start] = 0;
    vector <int> from(graph.size(), -1);
    vector <bool> visited(graph.size());
    for (int i = 0; i < graph.size(); i++) {
        int nearest = -1;
        for (int v = 0; v < graph.size(); v++) {
            if (!visited[v]) {
                if (nearest == -1 or dist[nearest] > dist[v]) {
                    nearest = v;
                }
            }
        }
        visited[nearest] = true;
        for (auto& [to, weight] : graph[nearest]) {
            if (dist[to] > dist[nearest] + weight) {
                dist[to] = dist[nearest] + weight;
                from[to] = nearest;
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
        if (d != 1e9) {
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