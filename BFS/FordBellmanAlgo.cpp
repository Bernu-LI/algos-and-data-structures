#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, weight;
};

vector <int> getPath(vector <int>& from, int finish) {
    vector <int> path;
    for (int v = finish; v != -1; v = from[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

pair <vector <int>, vector <int>> fordBellman(int vertexCount, vector <Edge>& edges, int start) {
    vector <int> dist(vertexCount, INT_MAX);
    dist[start] = 0;
    vector <int> from(vertexCount, -1);
    for (int i = 0; i < vertexCount - 1; i++) {
        for (auto& [a, b, weight] : edges) {
            if (dist[a] != INT_MAX and dist[b] > dist[a] + weight) {
                dist[b] = dist[a] + weight;
                from[b] = a;
            }
        }
    }
    return {dist, from};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <Edge> edges;
    for (int i = 0; i < m; i++) {
        int from, to , weight;
        cin >> from >> to >> weight;
        edges.push_back({from, to, weight});
    }
    int start;
    cin >> start;
    auto [dist, from] = fordBellman(n, edges, start);
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