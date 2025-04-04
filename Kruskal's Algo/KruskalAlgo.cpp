#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    Edge(int from_, int to_, int weight_): from(from_), to(to_), weight(weight_) {}
    int from, to, weight;
    bool operator < (const Edge& edge) const {
        return this->weight < edge.weight;
    }
};

struct DSU {
    DSU(int n): parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    vector <int> parent;
    vector <int> rank;

    int find(int v) {
        if (v != parent[v]) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[x] < rank[y]) {
            parent[x] = y;
        }
        else {
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
};

vector <Edge> kruskalAlgo(vector <Edge>& edges, int n) {
    DSU dsu(n);
    vector <Edge> mst;
    for (auto& edge : edges) {
        if (dsu.find(edge.from) != dsu.find(edge.to)) {
            dsu.unite(edge.from, edge.to);
            mst.push_back(edge);
        }
    }
    return mst;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <Edge> edges;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.emplace_back(from - 1, to - 1, weight);
    }
    sort(edges.begin(), edges.end());
    vector <Edge> mst = kruskalAlgo(edges, n);
    int counter = 0;
    for (const Edge& edge : mst) {
        counter += edge.weight;
    }
    cout << counter;
    return 0;
}