#include "bits/stdc++.h"
using namespace std;
const int maxn = 1005;

int m,n,a[maxn][maxn];
int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};
bool visited[maxn][maxn];

bool isValid(int r, int c) {
    return (r >= 1 && r <= m && c >= 1 && c <= n && !visited[r][c] && a[r][c] == 1);
}

int DFS(int r, int c) {
    int size = 1;

    visited[r][c] = true;
    for (int k = 0; k < 4; k++) {
        if (isValid(r + x[k], c + y[k])) {
            size += DFS(r+x[k], c + y[k]);
        }
    }
    return size;
}

int main() {
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                res = max(res, DFS(i,j));
            }
        }
    }

    cout << res;

    return 0;
}