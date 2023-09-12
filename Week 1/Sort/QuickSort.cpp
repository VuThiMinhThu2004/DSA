#include "bits/stdc++.h"
using namespace std;

int partition(int a[], int l, int r) {
    int pivot = a[r];//phan tu cuoi cung
    int i = l-1;

    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        int p = partition(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}


int main() {
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    quickSort(a,0,n-1);

    for (int x : a) cout << x << " ";
}