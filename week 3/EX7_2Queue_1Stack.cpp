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
        return (head == nullptr);
    }

    int getFront() {
        if (isEmpty()) return -1;
        return head->value;
    }

    int getSize() {
        return size;
    }

    void insertTail(int value) {
        Node *newNode = new Node(value);
        ++size;

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

    void deleteHead() {
        if (isEmpty()) {
            return;
        }
        --size;
        
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
    
        Node *temp = head->next;
        delete head;
        head = temp;
    }

    void printList() {
        Node *p = head;

        while (p != nullptr) {
            cout << p->value << " ";
            p = p->next;
        }
    }    
};

Queue q1,q2;

int Remove() {//reverse
    while (q1.getSize() > 1) {
        q2.insertTail(q1.getFront());
        q1.deleteHead();
    }

    int ans = q1.getFront();
    q1.deleteHead();

    while(!q2.isEmpty()) {
        q1.insertTail(q2.getFront());
        q2.deleteHead();
    }

    return ans; //Top: dinh stack
}


int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s == "push") {//insert
            int data; cin >> data;
            q1.insertTail(data);
        } else {//remove
            cout << "Top = " << Remove() << endl;
            if (n == 0) {
                q1.printList();
                return 0;
            }
        }
    }
    int top = Remove();
    q1.printList();
    cout << top;
}