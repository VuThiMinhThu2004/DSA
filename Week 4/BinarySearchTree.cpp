#include "bits/stdc++.h"
using namespace std;

class BinarySearchTree{
    struct Node{
        int key, value;
        Node *left = nullptr;
        Node * right = nullptr;
        Node(int value) {
            this->value = value;
        }
    };
    Node *root = nullptr;
public:
    bool search(Node *root, int key) {
        if (root == nullptr) return false;
        //Th1: key = root->value
        if (key == root->value) {
            return true;
        } else if (key < root->value) {//TH2: left child
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

    Node *insert(Node *root, int key) {// duyet cay tim nut la thoa man
        if (root == nullptr) {
            Node *newNode = new Node(key);
            return newNode;
        }
        if (key < root->value) {
            root->left = insert(root->left, key);
        }
        else if (key > root->value) {
            root->right = insert(root->right, key);
        }
        return root;
    }

    Node *nodeParent(Node *root) {
        Node *p = root;
        while (p != nullptr && p->left != nullptr) {
            p = p->left;
        }
        return p;
    }
    
    Node *Delete(Node *root, int key) {
        if (root == nullptr) return root;
        if (key < root->value) Delete(root->left, key);
        else if (key > root->value) Delete(root->right, key);
        else {
            //TH1: root la nut la (0 con): di tim nut cha cua nut la nay
            if (root->left == nullptr) {
                Node *tmp = root->right;
                delete root;
                return tmp;
            }
            else if (root->right == nullptr) {
                Node *tmp = root->left;
                delete root;
                return tmp;
            }
            else {
                Node *tmp = nodeParent(root);
                root->value = tmp->value;
                root->right = Delete(root->right, tmp->value);
            }
        }
    }
};

int main() {
    int N; cin >> N;
    int q = N-1;
    BinarySearchTree g;
    while (q--) {
        int p,u; cin >> p >> u;
        g.insert(p);
    }
}