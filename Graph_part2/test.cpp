#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;

int n, m, parent[10005];
vector<int> adj[10005];
bool visited[10005];
vector<ii> edge;
bool cycle(int u, int s, int t) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if ((u == s && v == t) || (u == t && v == s)) continue;//xoa canh s,t
        if (!visited[v]) {
            parent[v] = u;
            if (cycle(v,s,t)) return true;
        } else if (parent[u] == v) return true;
    }

    return false;
}

void DFS(int u, int s, int t) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if ((u == s && v == t) || (u == t && v == s)) continue;//xoa canh s,t
        if (!visited[v]) {
            DFS(v, s, t);
        }
    }
}

int tplt(int s, int t) {
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            DFS(i, s, t);
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u,v; cin >> u >> v;
        edge.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    ii res;
    for (auto e : edge) {
        int s = e.first, t = e.second;
        if (tplt(s,t) == 1 && !cycle(1,s,t)) {
            res.first = s;
            res.second = t;
        }
    }
    cout << res.first << " " << res.second;
}