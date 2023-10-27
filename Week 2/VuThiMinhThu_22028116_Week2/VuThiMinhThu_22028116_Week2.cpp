#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5+5;
int n,a[MAXN];

//Selection Sort
void SelectionSort() {
    for (int i = 0; i < n; i++) {
        int id = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[id]) {
                id = j;
            }
        }
        swap(a[i],a[id]);
        for (int k = 0; k < n; k++) cout << a[k] << " ";
        cout << endl;
    }
}

//Insertion Sort
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

//Bubble Sort
void BubbleSort() {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(a[i],a[j]); //ptu max se chuyen xuong cuoi dong
            }
        }
        for (int k = 0; k < n; k++) cout << a[k] << " ";
        cout << endl;
    }
}

//Merge Sort
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

//Quick Sort
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