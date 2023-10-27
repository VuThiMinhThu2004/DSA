#include "bits/stdc++.h"
using namespace std;

vector<int> adj[1005];
bool final = true;

//kiem tra nut co toi da 2 con (khong tinh nut cha)
void DFS(int u, int parent) {
    int cnt = 0;
    for (auto v : adj[u]) {
        if (v == parent) continue;
        cnt++;
        DFS(v, u);
    }

    if (cnt > 2) final = false;
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(0,-1);//vi theo de bai nut cua cay >= 0
    if (final) cout << "yes";
    else cout << "no";
}

/*
Cây nhị phân là cây mà mỗi đỉnh có tối đa 2 đỉnh con. Viết chương trình nhập vào một cây có đỉnh và kiểm tra xem
có phải là cây nhị phân hay không (các đỉnh của cây được đánh số từ đến và gốc của cây là đỉnh ).
5
0 1
1 2
2 3
3 4

->yes
*/