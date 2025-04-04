#include <iostream>
#include <vector>

using namespace std;

void dfs(vector <vector <int>>& graph, int v, vector <int>& parent) {
    for (int to : graph[v]) {
        if (to != parent[v]) {
            parent[to] = v;
            dfs(graph, to, parent);
        }
    }
}

vector <int> pruferCode(vector <vector <int>>& graph) {
    vector <int> parent(graph.size(), -1);
    dfs(graph, graph.size() - 1, parent);
    vector <int> degree(graph.size(), 0);
    int ptr = -1;
    for (int v = 0; v < graph.size(); v++) {
        degree[v] = graph[v].size();
        if (degree[v] == 1 and ptr == -1) {
            ptr = v;
        }
    }
    vector <int> pruferCode;
    int leaf = ptr;
    for (int i = 0; i < graph.size() - 2; i++) {
        int p = parent[leaf];
        pruferCode.push_back(p);
        degree[p]--;
        if (degree[p] == 1 and p < ptr) {
            leaf = p;
        }
        else {
            ptr++;
            while (ptr < graph.size() and degree[ptr] != 1) {
                ptr++;
            }
            leaf = ptr;
        }
    }
    return pruferCode;
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
    for (int number : pruferCode(graph)) {
        cout << number + 1 << " ";
    }
    return 0;
}