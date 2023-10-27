#include "bits/stdc++.h"
using namespace std;
const int MAXN = 10;
//Tham so mang: luu y mang nhieu chieu (Trong loi goi ham thi a[][N] - Phai co so lg cot de tinh duoc bo nho cua mang)
//Co the tham so hoa chieu thu nhat(mang 2 chieu)
void Solve(int a[][MAXN]) {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            cout << a[i][j] << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //Cần giải phóng bộ nhớ khi chấm dứt sử dụng

    int* m[n];
    for (int i = 0; i < n; i++) {
        m[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
}