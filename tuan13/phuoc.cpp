#include <bits/stdc++.h>

using namespace std;
int n, a[1007][1007];

int visit[1007];

void DFS (int i) {
    visit[i] = 1;
    for (int j = 1; j <= n; j++) {
        if (!visit[j] && a[i][j]) {
            a[i][j] = 0;
            a[j][i] = 0;
            DFS(j);
        }
    }
} 


int main () {
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <=n; i++) {
        if (!visit[i]) {
            DFS(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}