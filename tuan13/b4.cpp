#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int MAXN = 1005;
#define ll long long

typedef pair<ll,int> ii;
vector<ii> adj[MAXN];
int visited[MAXN];

void DFS(int u, ll t, ll &res) {
    visited[u] = true;
    res = max(res,t);
    sort (adj[u].begin(), adj[u].end());
    for (auto v : adj[u]) {
        if (!visited[v.second]) {
            DFS(v.second, t+v.first, res);
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({t, v});
    }    

    ll res = 0;
    DFS(k,0, res);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ll tmp = 0;
            DFS(i,0, tmp);
            res += tmp;
        }
    }
    cout << res;
    return 0;
}

/*
void DFS(int u, int &res) {
    int t = 0;
    res = max(res, t);
    visited[u] = 1;
    sort(adj[u].begin(), adj[u].end());
    for (auto v : adj[u]) {
        if (!visited[v.first]) {
            t += v.second;
            DFS(v.first,res);
        }
    }
}*/
