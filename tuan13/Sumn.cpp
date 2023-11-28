#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e6+1;
int N, cnt = 1, k;//truong hop lay 0 la 1cach
int a[maxn];
bool check(int i, int n) {
    if (n == 0 || i < a[n-1]) return true;
    //if(i == a[n-1]) return false;
    return false;
}

void backtrack(int n) {
    for (int i = N-1; i >= 1; i--) {
        if (check(i, n)) {
            k += i;
            a[n] = i;
            if (k == N) ++cnt;
            else if (k < N) {
                backtrack(n+1);
            }
            //lay xong phai tra lai
            k -= i;
        }
    }
}

int countWays(int N, int prev) {//N,0
    if (N == 0) {
        return 1; // Nếu N = 0, tồn tại một cách duy nhất là chi cho so 0
    }

    int ways = 0;
    for (int i = prev + 1; i <= N; ++i) {
        ways += countWays(N - i, i);
    }

    return ways;
}

int main() {
    cin >> N;
    backtrack(0);
    cout << cnt;
}