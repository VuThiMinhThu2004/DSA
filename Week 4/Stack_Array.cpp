#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5;

class Stack {
private:
    int size = 0;
    int a[MAXN];
public:
    bool isEmpty() { //O(1)
        return size == 0;
    }

    int getSize() {
        return size;
    }

    bool isFull() {
        return size == MAXN;
    }

    void insert(int key) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        ++size;
        a[MAXN - size] = key;
    }

    int getTop() {
        return a[MAXN-size];
    }

    void Delete() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        a[MAXN-size] = 0;
        size--;
    }

    void print() {
        while (size--) {
            cout << a[MAXN - size -1] << " ";
        }
    }
};

int main() {
    int n = 5;
    Stack st;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "push") {
            int x; cin >> x;
            st.insert(x);
        }
        else if (s == "pop") st.Delete();
        else if (s == "top") cout << st.getTop() << endl;
    }
    st.print();
}
