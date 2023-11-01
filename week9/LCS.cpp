#include "bits/stdc++.h"
using namespace std;

void Lcs(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> F(max(n,m) + 1, vector<int>(max(n,m), 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                F[i][j] = F[i-1][j-1] + 1;
            } else {
                F[i][j] = max(F[i-1][j], F[i][j-1]);
            }
        }
    }

    cout << "Xau con chung dai nhat la: " << F[n][m] << endl;
}
int main() {
    string a = "AGGTAB";
    string b = "GXTXAYB";
    Lcs(a,b);
}