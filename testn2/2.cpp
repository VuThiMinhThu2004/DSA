#include "bits/stdc++.h"
using namespace std;

void selectionSort(int *a, int n) {
    int m = n-2;
    int *arr = new int[m];
    
    for (int i = 0; i < m; i++) {
        arr[i] = a[i+1];
    }

    for (int i = 0; i < m; i++) {
        int id = i;
        for (int j = i+1; j < m; j++) {
            if (arr[j] < arr[id]) {
                id = j;
            }
        }
        swap(arr[i],arr[id]);
    }

    for (int i = 0; i < m; i++) {
        a[i+1] = arr[i];
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