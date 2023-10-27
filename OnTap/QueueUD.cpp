#include "bits/stdc++.h"
using namespace std;
#define INF -1

class Queue {
private:
struct Node {
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node() {}

    Node(int data) {
        this->data = data;
    }
};

public:
    int size = 0;
    Node *front = nullptr;
    Node *back = nullptr;

    Queue() {}

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    int getFront() {
        if (!front) return INF;
        return front->data;
    }

    int getBack() {
        if (!back) return INF;
        return back->data;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        if (front == nullptr) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
        size++;
    }

    void pop() {
        if (!front) return;
        --size;
        Node *head = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;    
        }       
        delete head;
    }    
};


void solve1(int n) {
    Queue q;
    vector<int> res;
    q.push(6); q.push(8);

    while (true) {
        int u = q.getFront(); q.pop();
        res.push_back(u);
        if (res.size() == n) break;
        q.push(10 * u + 6);
        q.push(10 * u + 8);
    }

    for (auto x : res) cout << x << " ";
}

void solve(int n) {
    queue<int> q;
    vector<int> res;
    q.push(6); q.push(8);

    while (true) {
        int u = q.front(); q.pop();
        res.push_back(u);
        if (res.size() == n) break;
        q.push(10 * u + 6);
        q.push(10 * u + 8);
    }

    for (auto x : res) cout << x << " ";
}

void test(int n) {
    Queue q;
    while (n--) {
        int op; cin >> op;
        if (op == 1) {
            int data; cin >> data;
            q.push(data);
        } else if (op == 2) {
            q.pop();
        } else {
            cout << q.getFront() << endl;
        }
    }
}
int main() {
    solve1(5);
   //test(10);
}