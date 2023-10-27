#include "bits/stdc++.h"
using namespace std;
#define INF 1 << 30

class Queue {
private:
    struct Node {
        int value;
        Node *next = nullptr;

        Node(){}
        Node(int value) {
            this->value = value;
        }
    };
public:
    Node *front = nullptr;
    Node *back = nullptr;
    int size = 0;

    Queue() {}

    int getFront() {
        if(!front) return INF;
        return front->value;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if (!front) return true;
        return false;
    }
    
    void push(int value) {
        Node *newNode = new Node(value);
        if (!front) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        ++size;
    } 

    void pop() {
        if (!front) return;

        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        --size;
    }
};

int main() {
    int t; cin >> t;
    Queue Q;
    while (t--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            Q.push(x);
        } else if (op == 2) {
            Q.pop();
        } else if (op == 3) {
            cout << Q.getFront() << "\n";
        }
    }
}