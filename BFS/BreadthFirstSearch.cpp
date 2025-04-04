#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair <vector <int>, vector <int>> bfs(vector <vector <int>>& graph, int start) {
    vector <int> dist(graph.size(), INT_MAX);
    vector <int> from(graph.size(), -1);
    queue <int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : graph[v]) {
            if (dist[to] == INT_MAX) {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }
    return {dist, from};
}

vector <int> getPath(vector <int> from, int vertex) {
    vector <int> path;
    for (int v = vertex; v != -1; v = from[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector <vector <int>> graph(v);
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int start;
    cin >> start;
    vector <int> dist = bfs(graph, start).first;
    vector <int> from = bfs(graph, start).second;
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
        cout << v << ' ';
    }
    return 0;
}  