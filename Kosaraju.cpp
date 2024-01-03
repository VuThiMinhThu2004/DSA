#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> adj[1005], t_adj[1005];
bool visited[1005];
stack<int> st;

void nhap() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);//graph
        t_adj[y].push_back(x);//transpose graph
    }
    memset(visited, false, sizeof(visited));
}

void DFS1(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) DFS1(v);
    }
    st.push(u);
}

void DFS2(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : t_adj[u]) {
        if (!visited[v]) DFS2(v);
    }
}

void Kosaraju() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) DFS1(i);
    }

    memset(visited, false, sizeof(visited));

    int scc = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!visited[u]) {
            ++scc;
            cout << "SCC " << scc << ": ";
            DFS2(u);
            cout << "\n";
        }
    }
}

int main() {
    nhap();
    Kosaraju();
}

/*
7 8
1 2 
2 3
3 1
3 6
6 4
4 5
5 7
7 4
*/