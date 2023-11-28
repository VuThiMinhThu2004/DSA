#include "bits/stdc++.h"
using namespace std;
const int maxn = 1005;
int n, a[maxn][maxn];
vector<int> adj[maxn];
bool visited[maxn];

void DFS(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int tplt() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i][i] == 1 && !visited[i]) {
            res++;
            DFS(i);
        }
    }
    return res;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i != j && a[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    memset(visited, false, sizeof(visited));
    cout << tplt();
}

/*
void DFS(int u, int &res) {
    int t = 0;
    res = max(res, t);
    visited[u] = 1;
    sort(adj[u].begin(), adj[u].end());
    for (auto v : adj[u]) {
        if (!visited[v.first]) {
            t += v.second;
            DFS(v.first,res);
        }
    }
}



#include "bits/stdc++.h"
using namespace std;
const int maxn = 1005;
int n, a[maxn][maxn];
vector<int> adj[maxn];
bool visited[maxn];

void DFS(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int tplt(int i) {
    memset(visited, false, sizeof(visited));
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            res++;
            DFS(i);
        }
    }
    return res;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i != j && a[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int ans = maxn;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, tplt(i));
    }
    cout << ans;
}
*/