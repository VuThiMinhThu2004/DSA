#include "bits/stdc++.h"
using namespace std;

int n, parent[1005];
vector<int> adj[1005];
bool visited[1005];
vector<int> leaves;

void DFS(int u, int height) {
    visited[u] = true;
    leaves.push_back(height);

    for (auto v : adj[u]) {
        if (!visited[v]) {
            DFS(v, height + 1);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }

    memset(visited, false, sizeof(visited));
    DFS(0, 0);

    int Htree = *max_element(leaves.begin(), leaves.end());
    int cnt = 0;

    for (auto x : leaves) {
        if (x == Htree) cnt++;
    }     

    cout << cnt;
}


/*
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> adj[1005];
bool visited[1005];
vector<int> leaves;

void DFS(int u, int leave) {
    visited[u] = true;
    leaves.push_back(leave);

    for (auto v : adj[u]) {
        if (!visited[v]) {
            DFS(v, leave + 1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    DFS(0,0);

    int cnt = 0;
    int Htree = *max_element(leaves.begin(), leaves.end());
    for (auto x : leaves) {
        if (x == Htree) cnt++;
    }
    cout << cnt;
}
*/