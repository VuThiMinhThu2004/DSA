#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;

int n, m, parent[1005]; 
bool visited[1005] = {false};
vector<ii> adj[1005];

void addEdges() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

void dijkstra(int s) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0,s});//s =  start 
    vector<int> d(n+1, 1e9);
    d[s] = 0;
    
    while (!q.empty()) {
        ii t = q.top(); q.pop();
        
        int dist = t.first,  u = t.second;
        if (dist > d[u]) continue;

        for (ii e :  adj[u]) {
            int v = e.first, w = e.second;//e = edge(u,v), w(u,v)
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});//dist (s,v), v
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}
int main() {
    
}