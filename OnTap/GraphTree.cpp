#include "bits/stdc++.h"
using namespace std;

int n,m;
vector<int> adj[1005];
bool visited[1005];
bool final = true;

void DFS(int u, int depth) {
    visited[u] = true;
    int cnt = 0;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            cnt++;//dem con
            if (cnt > 2) {
                final = false;
                return;
            }

            DFS(v,depth+1);
        }
    }
    if (cnt > 2) final = false; //khong phai cay nhi phan
}
int main() {
    cin >> n;
    m = n-1;
    int u,v;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);        
    }

    DFS(0,0);

    if(final) cout << "YES";
    else cout << "NO";
}

/*
5
0 1
1 2
2 3
3 4
*/