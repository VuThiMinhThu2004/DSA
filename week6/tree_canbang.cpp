/*Cây nhị phân cân bằng là cây nhị phân có độ cao lớn nhất của các đỉnh lá (độ sâu của cây) là nhỏ nhất có thể. Viết
chương trình nhập vào một cây có đỉnh và kiểm tra đó có phải là cây nhị phân cân bằng hay không (các đỉnh của
cây được đánh số từ đến và gốc của cây là đỉnh ).*/

#include "bits/stdc++.h"
using namespace std;

int N;
bool final = true;
vector<int> adj[1005];
vector<int> leaves;

void DFS(int u, int depth, int parent) {
    if (adj[u].size() == 1 && adj[u][0] == parent) {// nut la
        leaves.push_back(depth);
        return;
    }

    int cnt = 0;
    for (auto v : adj[u]) {
        if (v == parent) continue;

        cnt++;
        if (cnt > 2) {
            final = false;
            return;
        }

        DFS(v,depth+1,u);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N; 
    for (int i = 0; i < N-1; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (!leaves.empty()) {
        int mx = leaves[0], mn = leaves[0];
        for (auto it : leaves) {
            mx = max(mx, it);
            mn = min(mn, it);
        }   
        
        if (mx - mn > 1) final = false; //cay can bang thi do cao chenh lech <= 1
    }

    if (final) cout << "yes";
    else cout << "no";
}

/*
5
0 1
1 2
2 3
3 4
*/