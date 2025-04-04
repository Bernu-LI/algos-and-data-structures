#include <iostream>
#include <vector>

using namespace std;

vector <int> getPath(vector <vector <int>>& next, int start, int finish) {
    vector <int> path;
    for (int v = start; v != -1; v = next[v][finish]) {
        path.push_back(v);
    }
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> dist(n, vector <int>(n, INT_MAX));
    vector <vector <int>> next(n, vector <int>(n, -1));
    for (int v = 0; v < n; v++) {
        dist[v][v] = 0;
    }
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        if (dist[from][to] > weight) {
            dist[from][to] = weight;
            next[from][to] = to;
        }
    }
    for (int v = 0; v < n; v++) {
        for (int from = 0; from < n; from++) {
            for (int to = 0; to < n; to++) {
                if (dist[from][v] != INT_MAX and dist[v][to] != INT_MAX and dist[from][to] > dist[from][v] + dist[v][to]) {
                    dist[from][to] = dist[from][v] + dist[v][to];
                    next[from][to] = next[from][v];
                }
            }
        }
    }
    for (int from = 0; from < n; from++) {
        for (int to = 0; to < n; to++) {
            cout << dist[from][to] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int v : getPath(next, 0, 2)) {
        cout << v << " ";
    }
    return 0;
}