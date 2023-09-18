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
    int size = 0;
public:
    bool isEmpty() {
        if (head == nullptr) return true;
        return false;
    }

    int getSize() {
        return size;
    }

    int getTop() {
        return head->value;
    }

    void insertHead(int value) {// Push
        Node *newNode = new Node(value);
        ++size;
        if (head == nullptr) head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteHead() {
        if (isEmpty()) return;
        --size;
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
        cout << head->value << endl;
    }

    void printList2() {
        Node *p = head;
        while (p != nullptr) {
            cout << p->value << " ";
            p = p->next;
        }
    }
};

Stack s1,s2;

int Remove() {
    while (!s1.isEmpty()) {
        s2.insertHead(s1.getTop());
        s1.deleteHead();
    }
    int front = s2.getTop();
    s2.deleteHead();

    while (!s2.isEmpty()) {
        s1.insertHead(s2.getTop());
        s2.deleteHead();
    }
    return front; 
}

int main() {
    int n; cin >> n;
    
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int data; cin >> data;
            s1.insertHead(data);
        }
        else {
            cout << "Front = " << Remove() << endl;
            
            if (n == 0) {
                s1.printList2();
                return 0;
            }
        }
    }
    int front = Remove();
    cout << front << " ";
    s1.printList2();
    
    return 0;
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