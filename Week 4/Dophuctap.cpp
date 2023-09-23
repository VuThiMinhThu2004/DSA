#include <iostream>
using namespace std;
#define ll long long

ll Binpow(ll a, ll n) {
    if (n == 0) return 1;
    else if (n & 1) {
        return Binpow(a, n/2) * Binpow(a, n/2) * a;
    } else return Binpow(a, n/2) * Binpow(a, n/2);
}

ll solve(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res = res * i;
    }

    return res;
}
int main() {
	cout << Binpow(2,6);
    int n; cin >> n;
    
	return 0;
}