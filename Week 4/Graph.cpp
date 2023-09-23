#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+1;
vector<bool> visited(MAXN, false);

class Graph {
private:
    int N,M;
    vector<vector<int>> adj;

public:
    Graph(int N_, int M_) : N(N_), M(M_) {
        adj.resize(N);
    }

    void addEdge(int u, int v) {//DS ke
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const vector<int> &adjacent(int v) const {
        return adj[v];
    }

    int V() const {//N dinh
        return N;
    }

    int E() const {//M canh
        return M;
    }
};

void DFS(const Graph &g,int u) {
    //Tham dinh u
    cout << u << " ";
    visited[u] = true;

    for (const int &v : g.adjacent(u)) {
        if (!visited[v]) {
            DFS(g,v);
        }
    }
}

int main() {
    int n, m, s; cin >> n >> m >> s;
    Graph g(n,m);

    for (int i = 1; i <= m; i++) {
        int u,v; cin >> u >> v; //DS canh
        g.addEdge(u,v); //DS ke
    }

    for (int i = 1; i <= n; i++) {
        vector<int> adj = g.adjacent(i);
        sort(adj.begin(), adj.end()); //sort alpha - beta
    }
    DFS(g, s);
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