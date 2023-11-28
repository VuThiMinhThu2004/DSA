#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;

int n,m,s,t;
vector<ii> adj[1005];

void addEdges() {
    cin >> n >> m >> s >> t;
    
    for (int i = 1; i <= m; i++) {
        int u,v,w; cin >> u >> v; w = 1;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s}); //dist = 0, nut = s

    vector<int> d(n+1, 1e9); //ban dau dist (s, t) = 1e9
    d[s] = 0;
    
    while (!q.empty()) {
        ii t = q.top(); q.pop();

        int dist = t.first, u = t.second; //q{dist(s, u), u}
        
        if (dist > d[u]) continue;

        for (ii e : adj[u]) {
            int v = e.first, w = e.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }

    cout << d[t];//dist(s,t) min
}
int main() {
    addEdges();
    dijkstra();
}
/*
5 5 1 5
1 2
2 3
3 4
4 5
2 5
*/

