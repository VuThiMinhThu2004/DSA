#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];
stack<int> st;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(visited, false, sizeof(visited));
}

vector<int> d[1005];
int mx= 0;
void DFS(int u, int degree) {
    visited[u] = true;
    //sort(adj[u].begin(), adj[u].end());
    mx = max(mx, degree);
    d[degree].push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {            
            DFS(v,degree+1);
        }
    }
    
    st.push(u);
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) DFS(i,0);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    input();    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i,0);
        }
    }

    for (int i = 0; i <= mx; i++) {
        for (auto it : d[i]) {
            cout << it << " ";
        }
    }
    
    return 0;
}
/*
8 10
2 3
1 3
1 8
7 8
7 4
3 6
3 5
3 4
8 5
5 4
2 1 7 3 8 6 5 4
*/