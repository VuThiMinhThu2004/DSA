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
    }

    void deleteHead(int &front) {
        if (isEmpty()) {
            return;
        }
        front = head->value;
        
        Node *temp = head;
        head = head->next;
        delete temp;
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
            int front = -1;
            list.deleteHead(front);
        }
    }

    list.printList();
}