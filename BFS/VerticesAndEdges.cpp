#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> bfs(vector <vector <int>>& graph, int start) {
    vector <int> dist(graph.size(), INT_MAX);
    queue <int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : graph[v]) {
            if (dist[to] == INT_MAX) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int start, finish;
    cin >> start >> finish;
    vector <int> distFromStart = bfs(graph, start);
    vector <int> distFromFinish = bfs(graph, finish);
    for (int v = 0; v < n; v++) {
        if (distFromStart[v] + distFromFinish[v] == distFromStart[finish]) {
            cout << v << " ";
        }
    }
    cout << "\n";
    for (int v = 0; v < n; v++) {
        for (int to : graph[v]) {
            if (distFromStart[v] + 1 + distFromFinish[to] == distFromStart[finish]) {
                cout << v << " " << to << "\n";
            }
        }
    }
    return 0;
}