#include "bits/stdc++.h"
using namespace std;

void selectionSort(int *a, int n) {
    for (int i = 1; i < n-2; i++) {
        int pos_mn = i;
        for (int j = i+1; j < n-1; j++) {
            if (a[j] < a[pos_mn]) pos_mn = j;
        }
        swap(a[pos_mn], a[i]);
    }
}



int main() {
    int n; cin >> n;
    int *a = new int[n];
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    selectionSort(a,n);
    
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}