#include "bits/stdc++.h"
using namespace std;
int n,m;
int size_l, size_r;
multiset<int> l, r;

void chiaset() {
    size_l = l.size();
    size_r = r.size();

    if (size_l == size_r || size_l == size_r + 1) return;

    auto maxleft = std::prev(l.end());
    auto minright = r.begin();

    if (size_l < size_r) {
        l.insert(*minright);
        r.erase(minright);
    } else {
        r.insert(*maxleft);
        l.erase(maxleft);
    }

}

void solve(int op) {
    auto maxleft = std::prev(l.end());
    if (op == 1) {
        int x; cin >> x;

        if (x < *maxleft) {            
            l.insert(x);     
        } else {
            r.insert(x);
        }

        chiaset();
    } else if (op == 2) {
        l.erase(maxleft);
    } else if (op == 3) {
        cout << *maxleft << endl;
    }
}
int main() {
     cin >> n >> m;
    int a[n];

    for (int &it : a) cin >> it;

    sort(a,a+n);   

    if (n&1) {
        size_l = n/2+1;
        size_r = n/2;
    } else {
        size_l = size_r = n/2;
    }
    for (int i = 0; i < n; i++) {
        if (i < size_l) {
            l.insert(a[i]);
        } else r.insert(a[i]);
    }


    int op, x;
    while (m--) {
        cin >> op;
        solve(op);
    }
    
}