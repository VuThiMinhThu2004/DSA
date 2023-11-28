#include "bits/stdc++.h"
using namespace std;

int n, m, parent[1005];
vector<int> adj[1005];
bool visited[1005];

bool DFS(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (DFS(v))
                return true;
        }
        else {
            if (v != parent[u]) {
                return true; //la tao chu trinh vi "v" da dc tham ma khac cha(u) => chu trinh
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    if (DFS(0)) cout << "YES";
    else cout << "NO";
}