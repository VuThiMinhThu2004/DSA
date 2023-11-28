#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

const int maxn = 1005;
int n, m;
vector<ii> adj[maxn];

bool taken[maxn];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    memset(taken, false, sizeof(taken));
}

void Prim(int s) {
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    taken[s] = true;    
    int d = 0;
    for (ii x: adj[s]) {
        if (!taken[x.first]) {
            Q.push({x.second, x.first});//u,w
        }
    }

    while (!Q.empty()) {
        ii top = Q.top(); Q.pop();
        int u = top.second, w = top.first;
        if (!taken[u]) {
            d += w;
            taken[u] = true;
            for (ii x : adj[u]) {
                if (!taken[x.first]) {
                    Q.push({x.second, x.first});
                }
            }
        }
    }
    cout << d << endl;
}
int main() {
    input();
    Prim(1);
}