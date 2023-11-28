#include "bits/stdc++.h"
using namespace std;

bool check(string a, string b) {
    int m = (int)(b.size());
    int n = (int)(a.size());
    for (int i= 0; i < m; i++) {
        int j = 0;
        while (i < m && j < n && b[i] == a[j]) {
            i++;
            j++;
            if (j == n) return true;
        }
    }
    return false;
}
int main() {
    string a,b; cin >> a >> b;
    if(check(a,b)) cout << "YES";
    else cout << "NO";
    
    return 0;   
}