#include "bits/stdc++.h"
using namespace std;
class Node {
private:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
public:
    Node() {}
    Node(int data) {
        this->data = data;
    }

    bool search(Node *root, int key) {
        if (root->data == key) return true;
        else if (key < root->data) return search(root->left, key);
        else if (key > root->data) return search(root->right, key);
        return false;
    }

    Node *insert(Node *root, int data) {
        Node *newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
        }
        else if (data < root->data) {
            return insert(root->left, data);
        } else if (data > root->data) {
            return insert(root->right, data);
        }
        return root;
    }

    Node *findParent(Node *root, int data) {
        if (root->data == data) {
            return root;
        }
        else if (data < root->data) {
            return findParent(root->left, data);
        } else if (data > root->data) {
            return findParent(root->right, data);
        }
        return nullptr;
    }

    Node *deleteNode(Node *root, int data) {
        if (root == nullptr) {//Th1: root la nut la
            return root;
        } else if (root->left == nullptr || root->right == nullptr) {//Th2: Nut do chi co 1 nhanh
            Node *parent = findParent(root, data);
            
        }

    }
};

int main() {

}