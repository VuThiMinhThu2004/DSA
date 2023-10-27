#include "bits/stdc++.h"
using namespace std;
//Sap xep chon
const int MAXN = 1e5+5;
int n,a[MAXN];

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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    SelectionSort();

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
}