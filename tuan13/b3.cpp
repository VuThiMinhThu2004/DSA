#include "bits/stdc++.h"
using namespace std;
const int maxn = 1005;

int m,n,a[maxn][maxn];
int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};
bool visited[maxn][maxn];
int tx,ty,tc, temp;

bool isValid(int r, int c) {
    return (r >= 1 && r <= m && c >= 1 && c <= n && !visited[r][c] && a[r][c] == temp);
}

void DFS(int r, int c) {
    a[r][c] = tc;
    visited[r][c] = true;
    for (int k = 0; k < 4; k++) {
        if (isValid(r + x[k], c + y[k])) {
            DFS(r+x[k], c + y[k]);
        }
    }
}

int main() {
    cin >> m >> n;
    cin >> tx >> ty >> tc;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    temp = a[tx+1][ty+1];
    DFS(tx+1,ty+1);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}