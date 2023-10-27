#include "bits/stdc++.h"
using namespace std;

class Graph {
private:
    vector<int> adj[1005];
    bool visited[1005] = {false};
    int parent[1005];
    int n,m;
    int color[1005];
public:
    void addEdges() {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);//co huong
            //adj[v].push_back(u);
        } 
    }

    void DFS(int u) {
        visited[u] = true;

        for (auto v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                DFS(v);
            }
        }
    }

    void BFS(int u) {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto v : adj[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }
    }

    int tplt() {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cnt++;
                DFS(i);//BFS(i)
            }
        }
        return cnt;
    }

    //Kiem tra co duong di tu s->t tren do thi
    void path(int s, int t) {
        DFS(s);//duyet moi s vi neu co duong di thi t da tham
        if (!visited[t]) {
            cout << "NOT FOUND PATH\n";
        } else {
            stack<int> res;
            while (t != s) {
                res.push(t);
                t = parent[t];
            }
            res.push(s);

            while(!res.empty()) {
                cout << res.top() << " ";
                res.pop();
            }
        }
    }

    void shortestPath_BFS(int s, int t) {
        BFS(s);
        if (!visited[t]) {
            cout << "NOT FOUND PATH!" << endl;
        } else {
            stack<int> res;
            while (t != s) {
                res.push(t);
                t = parent[t];
            }
            res.push(s);

            while (!res.empty()) {
                cout << res.top() << " ";
                res.pop();
            }
        }
    }

    void reset() {
        memset(parent, 0, sizeof(parent));
        memset(visited, false, sizeof(visited));
    }

    //Kiem tra chu trinh tren do thi vo huong
    bool DFS_cycle(int u) {
        visited[u] = true;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                if (DFS_cycle(v)) {
                    return true;
                }
            } else if (parent[v] != u) return true;
        }

        return false;
    }

    bool BFS_cycle(int u) {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            
            for (auto v : adj[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    parent[v] = u;
                } else if (parent[v] != u) return true;
            }
        }
        return false;
    }

    //Kiem tra chu trinh cua do thi co huong
    bool DFS_cycle_CoHuong(int u) {
        color[u] = 1;
        for (int v : adj[u]) {
            if (color[v] == 0) {
                if (DFS_cycle_CoHuong(v)) {
                    return true;
                }
            } else if (color[v] == 1) {
                return true;
            }
        }
        color[u] = 2;
        return false;
    }
};

int main() {
    Graph g;
    g.addEdges();
    //cout << g.tplt();
    //g.shortestPath_BFS(1,5);
    if (g.BFS_cycle(1)) cout << "yes";
    else cout << "no";
}

/*
5 5 
1 2
2 3
3 4
4 5
2 5
s,t = 1 5

Kiem tra chu trinh
3 3
1 2
2 3
1 3
*/