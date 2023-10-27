#include "bits/stdc++.h"
using namespace std;

void selectionSort(int *a, int n) {
    int m = n-2;
    int *arr = new int[m];

    for (int i = 0; i < m; i++) {
        arr[i] = a[i+1];
    }
    
    for (int i = 0; i < m; i++) {
        int pos_mn = i;
        for (int j = i+1; j < m; j++) {
            if (arr[j] < arr[pos_mn]) pos_mn = j;
        }
        swap(arr[pos_mn], arr[i]);
    }

    for (int i = 0; i < m; i++) {
        a[i+1] = arr[i];
    }
}

void s(int *arr, int n) {
    for (int i = 1; i < n-2; i++) {
        int pos_mn = i;
        for (int j = i+1; j < n-2; j++) {
            if (arr[j] < arr[pos_mn]) pos_mn = j;
        }
        swap(arr[pos_mn], arr[i]);
    }
}
int main() {
    int n; cin >> n;
    int *a = new int[n];
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    s(a,n);
    
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}