#include "bits/stdc++.h"
using namespace std;


vector<int> adj[1005];
int n, m;
bool visited[1005];

void DFS(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        } 
    }
}

void solve() {
    cin >> n >> m;
    while(m--) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans++;
            DFS(i);
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(visited, false, sizeof(visited));
    solve();
}

/*
5 3
1 2
2 3
3 5
*/