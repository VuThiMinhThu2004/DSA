#include "bits/stdc++.h"
using namespace std;
int N = 7; //so nut
void maxHeap(int a[], int pos) { //O(logN)
    int largest;
    int left = 2*pos;
    int right = 2*pos + 1;

    if (left <= N && a[left] > a[pos]) 
        largest = left;
    else 
        largest = pos;

    if (right <= N && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != pos) {
        swap(a[pos], a[largest]);
        maxHeap(a,largest);
    }
}

void run_maxHeap(int a[]) {//O(N)
    for (int i = N/2; i >= 1; i--) {
        maxHeap(a,i);
    }
}

int main() {
    int a[N+1] = {-1,1,4,3,7,8,9,10};
    run_maxHeap(a);
    cout << "Gia tri cua mang sau khi ap dung ham maxheap: " << "\n";

    for (int i = 0; i < N+1; i++) {
        cout << a[i] << " ";
    }
}