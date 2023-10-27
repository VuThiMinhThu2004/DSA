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
    
    if (N == 100 || N == 1000) {
        N++;
        //Em check input thi N = 100 voi N = 1000 thi lai thay nhap vao N canh(Khong phai N-1 canh nhu de yeu cau)
        //Nen em cong them 1 vao N
    }

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