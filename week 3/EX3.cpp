#include "bits/stdc++.h"
using namespace std;

class Node{
public:
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node() {}
    Node(int value) {
        this->value = value;
    }
};

class DLinkedList{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    void insertTail(int value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void count_triplets() {
        Node *p = head->next;
        int count = 0;
        
        while (p->next != nullptr) {
            int x = p->prev->value;
            int y = p->value;
            int z = p->next->value;
            if (x + y + z == 0) count++;

            p = p->next;
        }

        cout << count << endl;
    }
};

int main() {
    int n; cin >> n;
    DLinkedList list;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        list.insertTail(x);
    }

    list.count_triplets();
}

/*
6
5 -3 -2 2 9 -11
*/