#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;

int n, m;
vector<int> adj[10005];
bool visited[10005];
vector<ii> leaves;

void DFS(int u, int leave, int &Hmin) {
    visited[u] = true;
    Hmin = max(Hmin, leave);
    for (auto v : adj[u]) {
        if (!visited[v]) {
            DFS(v, leave+1, Hmin);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }

    int ans = 1005;
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        int Hmin = 0;
        DFS(i, 0, Hmin);
        ans = min(Hmin, ans);
        leaves.push_back({Hmin, i});
    }

    for (auto it : leaves) {
        if (it.first == ans) {
            cout << it.second << " ";
        }
    }
}