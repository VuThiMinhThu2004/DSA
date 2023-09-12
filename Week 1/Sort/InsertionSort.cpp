#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+5;
//sap xep chen

int n, a[MAXN];

void InsertionSort() {
    for (int i = 1; i < n; i++) {
        int pos = i - 1, x = a[i];
        while (pos >= 0 && a[pos] > x) {
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = x;
        for (int j = 0; j < n; j++) cout << a[j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    InsertionSort();

}

