#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

const int maxn = 10005;
int n, m, k;
vector<ii> adj[maxn];
bool taken[maxn];

void prim(int s) {
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    taken[s] = true;
    int d = 0;

    for (auto u : adj[s]) {
        if (!taken[u.first]) {
            Q.push({u.second, u.first});//u,w
        }
    }

    while (!Q.empty()) {
        ii top = Q.top(); Q.pop();
        int u = top.second, w = top.first;

        if (!taken[u]) {
            d += w;
            taken[u] = true;
            for (auto v : adj[u]) {
                if (!taken[v.first]) {
                    Q.push({v.second, v.first});
                }
            }
        }
    }
    cout << d;
}

void input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    memset(taken, false, sizeof(taken));
    prim(k);
}


int main() {
    input();
}