#include "bits/stdc++.h"
using namespace std;

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