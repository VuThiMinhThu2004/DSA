#include "bits/stdc++.h"
using namespace std;
#define ll long long

struct Node {
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node (){}

    Node(int data) {
        this->data = data;
    }
};

class LinkedList {
public:
    Node *insert(Node *&head, int data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = newNode;
            return head;
        }
        newNode->next = head;
        head = newNode;

        return head;
    }

    Node *insertTail(Node *&head, int data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            while (head->next == nullptr) {
                head = head->next;
            }
            head->next = newNode;            
        }
        return head;
    }

    int size(Node *head) {
        int cnt = 0;
        for (Node *p = head; p != nullptr; p = p->next) {cnt++;}
        return cnt;
    }
    void insertPos(Node *&head, int pos, int data) {
        int n = size(head);

        if (pos < 1 || pos > n+1) return;
        if (pos == 1) {
            insert(head, data);
            return;
        }

        Node *p = head;
        for (int i = 1; i <= pos-2; i++) {
            p = p->next;
        }

        Node *newNode = new Node(data);
        newNode->next = p->next;
        p->next = newNode;
    }


    Node *insertTail(Node *&head, int data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            while (head->next == nullptr) {
                head = head->next;
            }
            head->next = newNode;            
        }
        return head;
    }

    Node* addLastNode(Node *&head, int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->nextNode = nullptr;
        
        if (head == nullptr) {
            head = newNode;
            return head;
        }

        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        head = temp;
        return head;
    }



    void DeleteHead(Node *&head) {
        if (!head) return;

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteTail(Node *&head) {
        if (!head) return;

        Node *temp = head;
        if (temp->next == nullptr) {
            Node *tail = head;
            delete tail;
            head = nullptr;
            return;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        Node *tail = temp->next;
        temp->next = nullptr;
        delete tail;
    }

    Node *deleteSingle(Node *head) {
        if (head == nullptr) return head;

        map<ll,ll> mp;

        for (Node *p = head; p != nullptr; p = p->next) {
            mp[p->data]++;
        }

        if (mp[head->data] == 1) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }

        for (Node *p = head; p->next != nullptr; p = p->next) {
            Node *curr = p->next;
            if (mp[curr->data] == 1) {//delete curr
                p->next = curr->next;
                delete curr;
            }
        }
    }
};

int main() {
    int n; cin >> n;
}