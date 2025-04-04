#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> shortestPathFasterAlgo(vector <vector <pair <int, int>>>& graph, int start) {
    vector <int> dist(graph.size(), INT_MAX);
    dist[start] = 0;
    queue <int> q;
    q.push(start);
    vector <bool> inQueue(graph.size());
    inQueue[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inQueue[v] = false;
        for (auto [to, weight] : graph[v]) {
            if (dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;
                if (!inQueue[to]) {
                    q.push(to);
                    inQueue[to] = true;
                }
            }
        }
    }
    return dist;
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
    vector <int> dist = shortestPathFasterAlgo(graph, start);
    for (int d : dist) {
        cout << d << " ";
    }
    return 0;
}