#include "bits/stdc++.h"
using namespace std;

class Node{
public:
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(){}

    Node(int value) {
        this->value = value;
    }
};

class Queue{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
public:
    bool isEmpty() {
        if (head == nullptr) return true;
        return false;
    }

    void insertTail(int value) {
        Node *newNode = new Node(value);
    
        if (head == nullptr) {//isEmpty
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return head->value;
    }

    int getSize() {
        return size;
    }

    void deleteHead() {
        if (isEmpty()) {
            return;
        }
        
        Node *temp = head;
        head = head->next;
        delete temp;

        --size;
    }

    void printList() {
        Node *p = head;

        while (p != nullptr) {
            cout << p->value << " ";
            p = p->next;
        }
    }    
};
int main() {
    Queue list;
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s == "enqueue") {//insert
            int data; cin >> data;
            list.insertTail(data);
        } else if (s == "dequeue") {//remove
            list.deleteHead();
        }
    }

    list.printList();
}