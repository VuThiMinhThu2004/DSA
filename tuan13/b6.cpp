#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e6+1;
int N,x, cnt, k;//truong hop lay 0 la 1cach
int a[maxn];

bool check(int i, int n) {
    if (n == 0 || pow(i,x) < a[n-1]) return true;
    return false;
}

void backtrack(int n) {
    for (int i = N-1; i >= 1; i--) {
        if (check(i, n)) {
            k += pow(i,x);
            a[n] = pow(i,x);
            if (k == N) ++cnt;
            else if (k < N) {
                backtrack(n+1);
            }
            //lay xong phai tra lai
            k -= pow(i,x);
        }
    }
}

int main() {
    cin >> N >> x;
    backtrack(1);
    cout << cnt;
}

/*
#include <iostream>
#include <cmath>
using namespace std;

int countWays(int x, int n, int num) {
    int val = pow(num, n);
    if (val > x) return 0; // Giá trị lũy thừa vượt quá x, không cách nào tạo ra x từ lũy thừa bậc n
    if (val == x) return 1; // Tìm thấy cách phân tích x thành lũy thừa bậc n
    return countWays(x, n, num + 1) + countWays(x - val, n, num + 1);
}

int main() {
    int x, n;
    cin >> x >> n;

    int result = countWays(x, n, 1);
    cout << result << endl;

    return 0;
}

*/