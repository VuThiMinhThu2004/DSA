#include "bits/stdc++.h"
using namespace std;

class LinkedList {
    struct Node {
        int value;
        Node *next = nullptr;
    }

    Node *insertHead(Node *head, int value) {
        Node *newNode = new Node;
        newNode->value = value;

        if (head == nullptr) {
            head = newNode;
            return newNode;
        }
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *insertTail(Node *head, int value) {
        Node *newNode = new Node;
        newNode->value = value;

        if (head == nullptr) {
            head = newNode;
            return head;
        }

        Node *p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newNode;
        return head;
    }

    Node* deleteDuplicates(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;
        map<int,int> mp;
        Node *curr = head;
        Node *prev = nullptr;

        while (curr->next == nullptr) {
            if (mp[curr->value] == 1) {
                prev->next = curr->next;
                delete curr;
            }
            else {
                mp[curr->value]++;
                prev = curr;
            }
            curr = prev->next;
        }
        return head;
    }

    void removeFirst() {
        if (head == NULL){
            return;
        }
        Node *second = head->next;//phantu thu 2
        delete head;//xoa phan tu dau
        head = second; //gan pt dau = ptu thu 2
    }

    void delete(Node *n ){
        if (n == head) removeFirst();
        if (n == nullptr) return;
        
        Node *p = head;

        for (; p != NULL && p->next != n; p = p->next) {}

        if (p == NULL)  return;
        p->next = n->next;
        delete n;
    }
    
    Node* deleteDuplicates(Node* head) {
        set<int> se;
        Node *p = head;
        while (p != null) {
            if (se.find(p->value) == se.end()) {//chua co
                se.insert(p->value);
            }
            else {
                delete(p);
            }
        }
        return head;
    }

    void printLast(Node* head, int k) {
        int size = 0;
        for (Node *p = head; p != nullptr; p=p->next) size++;

        Node *p =head;
        for (int i = 0; p != nullptr; i++,p = p->next) {
            if (i < size-k) continue;
            cout << p->value << " ";
        }

        
    }
};


int main() {
    
}