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

vector<int> quickSort(vector<int> a) {
    vector<int> left, equal, right;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] < a[0]) left.push_back(a[i]);
        else if (a[i] > a[0]) right.push_back(a[i]);
        else equal.push_back(a[i]);        
    }
    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    quickSort(a,0,n-1);

    for (int x : a) cout << x << " ";
}