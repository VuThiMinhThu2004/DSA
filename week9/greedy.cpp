#include "bits/stdc++.h"
using namespace std;
#define fi first 
#define se second 
typedef pair<double,double> ii;

double n,W, value, w;

bool cmp(ii x, ii y) {
    return x.fi/x.se > y.fi/y.se; //ty trong = value/w
}

int main() {
    cin >> n >> W;
    vector<ii> a;

    for (int i = 0; i < n; i++) {
        cin >> value >> w;
        a.push_back({value,w});
    }

    sort(a.begin(), a.end(), cmp);

    double res = 0, ans_w = 0;
    int id = 0;
    
    for (int i = 0; i < n; i++) {
        if (ans_w + a[id].se <= W) { 
            ans_w += a[id].se;
            res += a[id].fi;
        }
    }
    
    cout << res;
}
/*
3 50
60 10
100 20
120 30

cost:
6
5
4
*/


