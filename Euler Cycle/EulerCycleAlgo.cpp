#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void eulerCycle(vector <vector <int>>& graph, int v, vector <int>& result) {
    while (!graph[v].empty()) {
        int to = *graph[v].begin();
        graph[v].erase(graph[v].begin());
        auto it = find(graph[to].begin(), graph[to].end(), v);
        graph[to].erase(it);
        eulerCycle(graph, to, result);
    }
    result.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }
    for (vector <int>& v : graph) {
        if (v.size() % 2 != 0) {
            cout << ":(";
            return 0;
        }
    }
    vector <int> result;
    eulerCycle(graph, 0, result);
    if (result.size() != m + 1) {
        cout << ":(";
    }
    else {
        reverse(result.begin(), result.end());
        for (int v : result) {
            cout << v + 1 << " ";
        }
    }
    return 0;
}
