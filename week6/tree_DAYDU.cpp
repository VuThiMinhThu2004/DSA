/*Cây nhị phân đầy đủ là cây mà mỗi đỉnh có 0 hoặc 2 đỉnh con. Viết chương trình nhập vào một cây có đỉnh và kiểm
tra xem có phải là cây nhị phân đầy đủ hay không (các đỉnh của cây được đánh số từ đến và gốc của cây là
đỉnh ).*/
#include "bits/stdc++.h"
using namespace std;

int N; 
vector<int> adj[1005];
bool final = true;

void DFS(int u, int parent) {
    int cnt = 0;
    for (auto v : adj[u]) {
        if (v == parent) continue;
        cnt++;
        DFS(v,u);
    }
    if (cnt != 0 && cnt != 2) final = false; //Cay day du la cay co 0 | 2 con
}

int main() {
    cin >> N;

    for (int i = 1; i < N; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(0,-1);
    
    if (final) cout << "yes";
    else cout << "no";

    return 0;
}