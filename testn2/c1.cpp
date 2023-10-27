#include "bits/stdc++.h"
using namespace std;

struct Node{
    int value;
    Node *nextNode;
};
Node* addLastNode(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->nextNode = nullptr;
    
    if (head == nullptr) {
        head = new Node;
        head->value = value;
        head->nextNode = nullptr;
        return head;
    }

    Node *temp = head;
    while(temp->nextNode != NULL){
        temp = temp->nextNode;
    }

    temp->nextNode = newNode;
    return head;
}