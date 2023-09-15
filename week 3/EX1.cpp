#include "bits/stdc++.h"
using namespace std;
map<int,int> mp;

int main() {
    int n; cin >> n;
    int a[n];
    int res = 0;

    for (int &x : a) {
        cin >> x;
        res += mp[x]++;
    }
    cout << res;
    return 0;
}

/*
Given a list A of n integer numbers, your task is to write a program to 
count the number of pairs (i,j) that A[i]=A[j]
*/