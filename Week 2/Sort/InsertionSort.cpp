#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+5;
//sap xep chen
void InsertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int pos = i - 1, x = a[i];
        while (pos >= 0 && a[pos] > x) {
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = x;
        //for (int j = 0; j < n; j++) cout << a[j] << " ";
       // cout << endl;
    }
    for (int j = 0; j < n; j++) cout << a[j] << " ";
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    InsertionSort(a,n);

}

