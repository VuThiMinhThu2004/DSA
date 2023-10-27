#include "bits/stdc++.h"
using namespace std;

int BinarySearch(int a[], int l, int r, int key) {
    if (l <= r) {
        int mid = l + (r-l)/2;
        if (key == a[mid]) return mid;
        else if (key > a[mid]) BinarySearch(a,mid+1,r,key);
        else BinarySearch(a,l,mid-1,key);
    }
    return -1;
}
int main() {
    int n; cin >> n;
    int a[n];

    for (int &x : a) cin >> x;
    cout << BinarySearch(a,0,n-1,3);
}