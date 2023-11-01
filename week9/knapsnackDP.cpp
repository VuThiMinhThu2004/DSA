#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1005;
#define fi first 
#define se second 
typedef pair<int,int> ii;
vector<ii> a;
int n,W,value,weight;

void DP(int n,int W) {
    vector<vector<int> > F(n + 1, vector<int>(W + 1, 0)); 
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {//w
            if (w >= a[i-1].se) {
                F[i][w] = max(F[i][w], F[i-1][w-a[i-1].se] + a[i-1].fi);
            } else {
                F[i][w] = F[i-1][w];
            }
        }
    }
    cout << F[n][W] << endl;
}


int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> value >> weight;
        a.push_back({value, weight});
    }
    DP(n,  W);
}
/*
3 50
60 10
100 20
120 30
*/