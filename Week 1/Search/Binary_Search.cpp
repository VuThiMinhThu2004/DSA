#include "bits/stdc++.h"
using namespace std;
int n;
int BinarySearch(vector<int> a, int left, int right, int key) {
    int l = left, r = right;
    while (l <= r) {
        int mid = l + (r-l) / 2;
        if (a[mid] == key) {
            return mid;
        }
        else if (a[mid] < key) l = mid+1;
        else r = mid;
    }
    return -1;//NOT FOUND
}

int main() {
    ios_base::sync_with_stdio(false);
    int key;
    cin >> n >> key;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    cout << BinarySearch(a,0,n-1,key);
}

/*
5 5
1 2 3 4 5
*/