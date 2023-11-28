#include "bits/stdc++.h"
using namespace std;

int n,m;
vector<int> a[1005];
bool visited[1005];
vector<pair<int, int>> edge;

void DFS(int u, int s, int t) {
    visited[u] = true;
    for (auto v : a[u]) {
        //Neu xet u,v == s,t thi khong xet canh nay
        if (u == s && v == t || u == t && v == s) {
            continue;
        }
        if (!visited[v])
            DFS(v,s,t);
    }
}

int tplt(int s, int t) {
    int count = 0;
    memset(visited,false,sizeof(visited));

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            DFS(i,s,t);
        }
    }
    return count;
}

void canh_cau() {
    int cc = tplt(0,0);//la goc
    for (pair<int,int> e : edge) {
        int s = e.first, t = e.second;
        if (cc < tplt(s,t)) {
            //cout << s << " " << t << "\n";
            cout << "Đồ thị không có tính chất liên thông cạnh";
            return;
        }
    }

    cout << "Đồ thị có tính chất liên thông cạnh";
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

