#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100005], n, data;

bool check(int k) {
    while (2 * k < n) {
        int i = 2*k + 1;
        if (a[i] >= a[k] && a[i] < a[i+1]) continue;
        else return false;
        k++;
    }
    return true;
}
int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
        
    if (check(0)) cout << "YES";
    else cout << "NO";
    return 0;
}
/*
6
3 5 2 1 4 6
->NO

*/