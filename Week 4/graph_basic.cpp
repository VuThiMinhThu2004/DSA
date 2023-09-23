#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+1;

vector<vector<int>> adj(MAXN);
vector<bool> visited(MAXN, false);
int m,n,s;

void addEdge(int u, int v) {//DS ke
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
int main() {
    cin >> n >> m >> s;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        addEdge(u,v);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());//sort alpha - beta
    }
    DFS(s);
}

/*Input:
5 5 3
5 2
3 2
5 4
5 3
5 1

output: 3 2 5 1 4
*/