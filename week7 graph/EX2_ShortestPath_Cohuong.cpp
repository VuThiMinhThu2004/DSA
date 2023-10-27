#include "bits/stdc++.h"
using namespace std;
#define INF 1 << 30
int n,m,s,t;
bool visited[1005];
vector<int> a[1005];
int parent[10005];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int x = q.front(); q.pop();

        sort(a[x].begin(), a[x].end());

        for (auto v : a[x]) {
            if (!visited[v]) {
                q.push(v);
                parent[v] = x;
                visited[v] = true;
            }
        }
    }
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    queue<int> Q;
    
    dist[s] = 0;//dist[start]
    Q.push(s);
    visited[s] = true;
    
    while (!Q.empty()) {
        int curr = Q.front(); Q.pop();
        
        for (int i = 0; i < edges[curr].size(); i++) {
            int neighbour = edges[curr][i];
            
            if (!visited[neighbour] && dist[neighbour] > dist[curr] + 1) {
                visited[neighbour] = true;
                dist[neighbour] = dist[curr] + 1;
                Q.push(neighbour);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i != s) {
            if (dist[i] == INF) {
                dist[i] = -1;
            } else {
                dist[i] *= 6;
            }
        }
    }
    return dist;
}

void path(int s, int t) {
    BFS(s);
    
    if (!visited[t]) {
        cout << "-1";
    }
    else {
        vector<int> res;

        while (t != s) {
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());

        if (res.empty()) {
            cout << "yes";
        }

        cout << res.size() - 1 << endl;
        for (auto it : res) cout << it << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> s >> t;//dinh dau - cuoi
    for (int i = 1; i <= m; i++) {
        int u,v; cin >> u >> v;
        a[u].push_back(v);
        //a[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    path(s,t);
}
/*
5 5 1 5
1 2
2 3
3 4
4 5
2 5
*/