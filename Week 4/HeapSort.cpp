#include "bits/stdc++.h"
using namespace std;

void sink(int a[], int k, int N) {
    while (2 * k + 1 < N) {
        int j = 2 * k + 1;// left_child
        if (j + 1 < N && a[j] < a[j+1]) j++;//check left_child < right_chilf
        if (a[j] < a[k]) break;//parent > max_child
        swap(a[k], a[j]); //swap paren vs max_child
        k = j;//duyet xuong duoi tiep -> chim
    }
}

void heapSort(int a[], int N) {
    //phase 1: vun dong cay con trai sang cay con phai. cac nut cha thi de chim dan
    for (int k = N/2; k >= 0; k--) {
        sink(a, k, N);
    }
    
    //phase 2: lay phan tu goc (dau mang) swap ptu cuoi mang de dc mang da sap xep
    while (N > 1) {
        swap(a[0], a[--N]);
        sink(a, 0, N);
    }
}

int main() {
    int N = 6;
    int a[] = { 12, 11, 13, 5, 6, 7 };
    
    heapSort(a,N);
    
    for (auto it : a) cout << it << " ";
}