#include <bits/stdc++.h>
using namespace std;

long long Cnk(long long n, long long k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }

    return Cnk(n - 1, k - 1) + Cnk(n - 1, k);
}

long long graphNum(long long E, long long V)
{
    return 2 * E * Cnk((V * (V - 1) / 2), E);
}

int main()
{
    long long v, e;
    cin >> v >> e;
    cout << graphNum(v, e) << endl;
}