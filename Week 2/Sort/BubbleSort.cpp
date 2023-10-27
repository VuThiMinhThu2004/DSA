#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+5;
//sap xep noi bot

void BubbleSort(int *a, int n) {
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

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    BubbleSort(a, n);

    /*for (int i =0 ; i < n; i++) {
        cout << a[i] << " ";
    }*/
}