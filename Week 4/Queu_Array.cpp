#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+1;

class Queue {
private:
    int size = 0;
    int l = 0, r = 0;
    int a[MAXN];
public:
    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return size == MAXN;
    }

    void insertTail(int key) {
        a[r++] = key;
        size++;
    }

    int front() {
        return a[l];
    }

    void deleteHead() {
        l++, size--;
    }

    void print() {
        int i = l, j = r;
        while (i < j) {
            cout << a[i++] << " ";
        }
    }
};

int main() {
    int n; cin >> n;
    Queue q;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "push") {
            int x; cin >> x;
            if (q.isFull()) cout << "queue is full" << "\n";
            else q.insertTail(x);
        }
        else if (s == "pop") {
            if (q.isEmpty()) cout << "Queue is Empty!" << "\n";
            else q.deleteHead();
        }
        else if (s == "front") {
            if (q.isEmpty()) cout << "Queue is Empty!" << "\n";
            else cout << q.front() << "\n";
        }
    }

    q.print();
    return 0;
}