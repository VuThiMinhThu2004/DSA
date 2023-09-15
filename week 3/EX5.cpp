#include "bits/stdc++.h"
using namespace std;
//Last in first out
class Node{
public:
    int value;
    Node *next = nullptr;
    Node() {}
    Node(int value) {
        this->value = value;
    }
};

class Stack{
private:
    Node *head = nullptr; //Top = tren cung cua stack - coi la con tro head
public:
    bool isEmpty() {
        if (head == nullptr) return true;
        return false;
    }

    void insertHead(int value) {// Push
        Node *newNode = new Node(value);

        if (head == nullptr) head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteHead(int &top) {//Pop
        if (isEmpty()) return;
        if (head->next == nullptr) {
            head = nullptr;
        } else {
            head = head->next;
        }
    }

    void printReverse(Node *head) {
        if (head->next == nullptr) {
            return;
        }
        printReverse(head = head->next);
        cout << head->value << " ";

    }

    void printList() {
        if (isEmpty()) {
            cout << "Stack is empty!";
            return;
        }
        printReverse(head);
        cout << head->value;
    }
};

int main() {
    Stack list;

    int Q; cin >> Q;
    while (Q--) {
        string s; cin >> s;
        if (s == "push") {
            int value; cin >> value;
            list.insertHead(value);
        } else if (s == "pop") {
            int top = -1;
            list.deleteHead(top);
        }
    }
    
    list.printList();
}

/*
7
push 1
push 2
push 3
push 4
pop
pop
push 5
*/