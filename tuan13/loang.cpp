#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1005;
int a[maxn][maxn], m, n;
bool visited[maxn][maxn];

bool isValid(int row, int col) {
    return (row >= 1 && row <= m && col >= 1 && col <= n
            && !visited[row][col] && a[row][col]);
}

int DFS(int row, int col) {
    static int row_nbr[] = {-1, 0, 0, 1};
    static int col_nbr[] = {0, -1, 1, 0};

    visited[row][col] = true;
    int size = 1;

    for (int k = 0; k < 4; ++k) {
        if (isValid(row + row_nbr[k], col + col_nbr[k])) {
            size += DFS(row + row_nbr[k], col + col_nbr[k]);
        }
    }

    return size;
}

int main() {
    cin >> m >> n;
    int res = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] && !visited[i][j]) {
                res = max(res, DFS(i, j));
            }
        }
    }

    cout << res << endl;

    return 0;
}



/*
4 4
1 0 1 0
0 1 1 0
1 1 1 0
0 1 0 1


}
*/