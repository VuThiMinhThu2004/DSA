#include "bits/stdc++.h"
using namespace std;

class Node{
public:
    int value;
    Node *next = nullptr;

    Node(int data) {
        this->value = data;
    }
};

class LinkedList{
    Node *head = nullptr;
public:
    void Insert(int pos, int data) {
        //New node
        Node *newNode = new Node(data);

        if (pos == 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }

        //insert
        int cnt = 0;
        Node *p = head;
        while (cnt < pos-1 && p->next != nullptr) {
            cnt++;
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }

    void Delete(int pos) {
        if (head == nullptr) return;

        if (pos == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        int cnt = 0;
        Node *p = head;
        while (cnt < pos-1 && p->next != nullptr) {
            p = p->next;
            cnt++;
        }
        if (p->next == nullptr) return;
        
        Node *temp = p->next;
        p ->next = temp->next;
        delete temp;
    }

    void printList() {
        Node *p = head;
        while (p != nullptr) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

};

int main() {
    LinkedList list;

    int Q; cin >> Q;
    while (Q--) {
        string s; cin >> s;
        if (s == "insert") {
            int p,data; cin >> p >> data;
            list.Insert(p,data);
        }
        else if (s == "delete") {
            int p; cin >> p;
            list.Delete(p);
        }
            list.printList();

    }

    list.printList();
}

/*
5
insert 0 1
insert 1 3
insert 1 4
insert 2 2
delete 1
*/