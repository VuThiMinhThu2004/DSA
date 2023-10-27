#include "bits/stdc++.h"
using namespace std;

struct edge{
    int x,y,w;
    edge(int x, int y, int w) {
        this->x = x;
        this->y = y;
        this->w = w;
    }
};

int n,m, parent[1005], size[1005];
vector<edge> E;

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x,y,w; cin >> x >> y >> w; 
        edge e(x,y,w);
        E.push_back(e);
    }
   // sort(E.begin(), E.end(), cmp);
}

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i, size[i] = 1;
    }
}

int Find(int u) {
    if (u == parent[u]) return u;
    return parent[u] == Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v) return false;
    if (size[u] < size[v])  swap(u,v);

    size[u] += size[v];
    parent[v] = u;
    return true;
}

void Kruskal() {
    vector<edge> MST;
    int d = 0;
    sort(E.begin(), E.end(), [](edge x, edge y)->bool{
        return x.w < y.w;
    });

    for (edge e : E) {
        if (MST.size() == n-1) break;
        if (Union(e.x, e.y)) {
            MST.push_back(e);
            d += e.w;
        }
    }

    if (MST.size() < n-1) {
        cout << "Do thi khong lien thong!\n";
    } else {
        cout << d << endl;
        for (edge e : MST) {
            cout << e.x << " " << e.y << " " << e.w << endl;
        }
    }
}
int main() {
    input();
    init();
    Kruskal();
}