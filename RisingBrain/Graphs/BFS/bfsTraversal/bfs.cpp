#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;   // n = vertices, m = edges

    vector<vector<int>> adj(n);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // Remove this line if graph is directed
    }

    // BFS
    vector<bool> vis(n, false);
    queue<int> q;

    int start = 0;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = true;
                q.push(neigh);
            }
        }
    }
}