#include "bits/stdc++.h"
using namespace std;
int INF = -1e9;

class Tree {
private:
    struct Node {
        int data;
        Node *left = nullptr;
        Node *right = nullptr;

        Node (int data) {
            this->data = data;
        }
    };    

    Node *root = nullptr;

    void preorderTraversal(Node *node, vector<int> &res) {//duyet truoc
        if (node == nullptr) return;
        res.push_back(node->data);
        preorderTraversal(node->left, res);
        preorderTraversal(node->right, res);
    }

    void postorderTraversal(Node *node, vector<int> &res) {
        if (node == nullptr) return;
        postorderTraversal(node->left, res);
        postorderTraversal(node->right, res);   
        res.push_back(node->data);
    }

    void inorderTraversal(Node *node, vector<int> &res) {//duyet trung thu tu
        if (node == nullptr) return;
        inorderTraversal(node->left, res);
        res.push_back(node->data);
        inorderTraversal(node->right, res);
    } 
public:

    int getHeight(Node *node) {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    Node *find(Node *root, int u) {
        if (root->data == u) {
            return root;
        }
        return find(root->left, u);
        return find(root->right, u);
    }    

    void insert(int parentValue, int value) {
        if (root == nullptr) {
            root = new Node(parentValue);
            Node *newNode = new Node(value);
            root->left = newNode;
            return;
        }
        insert(root, value, parentValue);
    }

    void insert(Node* node, int value, int parentValue) {
        if (node == nullptr) {
            return;
        }
        if (node->data == parentValue) {
            if (node->left == nullptr) {
                node->left = new Node(value);
            } else {
                node->right = new Node(value);
            }
        } else {
            insert(node->left, value, parentValue);
            insert(node->right, value, parentValue);
        }
    }

    vector<int> getPreorder(Node *node) {
        vector<int> res;
        preorderTraversal(node, res);
        return res;
    }

    vector<int> getPostorder(Node * node) {
        vector<int> res;
        postorderTraversal(node, res);
        return res;
    }

    vector<int> getInorder(Node * node) {
        vector<int> res;
        inorderTraversal(node, res);
        return res;
    }

    bool isBinarySearchTree(Node *node) {
        if (node == nullptr) return true;
        if (node->data < node->left->data || node->data > node->right->data) return false;

        if (node->data > node->left->data) {
            return isBinarySearchTree(node->left);
        }
        if (node->data < node->right->data) {
            return isBinarySearchTree(node->right);
        }
    }

    void printTree(vector<int> a) {
        for (auto it : a) cout << it << " ";
        cout << endl;
    }
    
    void print() {
        cout << getHeight(root) << endl;
        vector<int> pre = getPreorder(root);
        printTree(pre);

        vector<int> post = getPostorder(root);
        printTree(post);

        if (isBinarySearchTree(root)) {
            vector<int> in = getInorder(root);
            printTree(in);
        }
        else cout << "NOT BINARY TREE!";
    }
};
int main() {
    int n,m; cin >> n >> m;
    Tree g;
    for (int i = 1; i <= m; i++) {
        int u,v; cin >> u >> v;
        g.insert(u,v);
    }
    
    g.print();
}

/*
Cho input là:
5  4
1  2
1  3
2  4
2  5

Thì output sẽ là:
2
1  2  4  5  3
4  5  2  3  1

4  2  5  1  3 #Đề sai: vì 2 là cha của 4 và 5 -> không phải cây tìm kiếm nhị phân.
*/