#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printPath(vector <vector <pair <int, int>>>& from, int a, int b) {
    vector <pair <int, int>> path;
    while (a != -1 and b != -1) {
        path.push_back({a, b});
        auto [pa, pb] = from[a][b];
        a = pa;
        b = pb;
    }
    reverse(path.begin(), path.end());
    for (auto [a, b] : path) {
        cout << a << " " << b << "\n";
    }
}

void bfs(int capacityA, int capacityB, int target) {
    vector <vector <int>> dist(capacityA + 1, vector <int>(capacityB + 1, INT_MAX));
    vector <vector <pair <int, int>>> from (capacityA + 1, vector <pair <int, int>>(capacityB, {-1, -1}));
    queue <pair <int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        if (a == target or b == target) {
            cout << dist[a][b] << "\n";
            printPath(from, a, b);
            return;
        }
        vector <pair <int, int>> to = {
            {capacityA, b},
            {a, capacityB},
            {0, b},
            {a, 0}
        };
        int deltaAB = min(a, capacityB - b);
        to.push_back({a - deltaAB, b + deltaAB});
        int deltaBA = min(b, capacityA - a);
        to.push_back({a + deltaBA, b - deltaBA});
        for (auto [ta, tb] : to) {
            if (dist[ta][tb] == INT_MAX) {
                dist[ta][tb] = dist[a][b] + 1;
                from[ta][tb] = {a, b};
                q.push({ta, tb});
            }
        }
    }
    cout << "Impossible";
}

int main() {
    bfs(5, 5, 4);
    return 0;
}