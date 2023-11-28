#include "bits/stdc++.h"
using namespace std;
int fa[256], fb[256];

int fA[256];
int main() {
    int t; cin >> t;
    while(t--) {
        string a,b; cin >> a >> b;
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] >= 'a' && a[i] <= 'z') {
                a[i] = a[i] - 'a' + 'A';
            } else fA[a[i]]++;

            fa[int(a[i])]++;
        }

        for (int i = 0; i < (int)b.size(); i++) {
            fb[b[i]]++;
        }

        bool check = true;
        for (int i = 0; i < (int)b.size(); i++) {
            if (fA[b[i]] > fb[b[i]] || fa[b[i]] < fb[b[i]]) {
                check = false;
                break;
            }
        }
        if (check)
            cout << "YES\n";
        else cout << "NO\n";
    }
    
}