#include "bits/stdc++.h"
using namespace std;

class Array {
private:
    int* a;
    int n,size;
public:
    Array(int _n) {
        this->n = _n;
        this->a = new int[n];
        this->size = 0;
    }

    ~Array() {
        delete[] a;
    }

    int at(int i) {
        return a[i-1];
    }

    int size() const {
        return size;
    }

};

int main() {
    //init
    int n; cin >> n;
    Array a(n);
    
}