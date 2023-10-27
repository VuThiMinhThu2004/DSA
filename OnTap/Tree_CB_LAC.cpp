#include "bits/stdc++.h"
using namespace std;

int n,m; 
vector<int> adj[1005];
vector<int> leaves;
bool visited[1005], final = true;

void DFS(int u, int depth) {
    visited[u] = true;
    leaves.push_back(depth);
    int cnt = 0;

    for (auto v : adj[u]) {
        if (!visited) {
            cnt++;
            if (cnt > 2) {
                final = false;
                return;
            }
            DFS(v,depth+1);
        }
    }

    if (cnt > 2) {
        final = false;
        return;
    }
}

void DFS2(int u, int depth, int parent) {
    if (adj[u].size() == 1 && adj[u][0] == parent) {// nut la
        leaves.push_back(depth);
        return;
    }

    int cnt = 0;
    for (auto v : adj[u]) {
        if (v == parent) continue;

        cnt++;
        if (cnt > 2) {
            final = false;
            return;
        }

        DFS2(v,depth+1,u);
    }
}

int main() {
    cin >> n;
    m = n-1;
    int u,v;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(0,0);
    int mx = *max_element(leaves.begin(), leaves.end());
    int mn = *min_element(leaves.begin(), leaves.end());

    if (mx - mn > 1) cout << "NO";
    else if (final) cout << "YES";
    else cout << "NO";
}