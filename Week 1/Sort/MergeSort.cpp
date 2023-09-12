#include "bits/stdc++.h"
using namespace std;


void merge(int a[], int left, int mid, int right) {//Thao tac tron
    int n1 = mid-left+1, n2 = right-mid;
    int l[n1], r[n2];

    for (int i = left; i <= mid; i++) {
        l[i-left] = a[i];
    }
    for (int i = mid+1; i <= right; i++) {
        r[i-mid-1] = a[i];
    }

    int i = 0, j = 0, cnt = left;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            a[cnt++] = l[i++];
        }
        else a[cnt++] = r[j++];
    }

    while (i < n1) a[cnt++] = l[i++];
    while (j < n2) a[cnt++] = r[j++];

}

void mergesort(int a[], int l, int r) {//chia mang
    if (l < r) {
        int m = l + (r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m, r);
    }
}
int main() {
    int n; cin >> n;
    int a[n];

    for (int &x : a) cin >> x;
    mergesort(a,0,n-1);

    for (int x : a) cout << x << " ";
}