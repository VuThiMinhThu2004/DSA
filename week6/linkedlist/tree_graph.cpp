#include "bits/stdc++.h"
using namespace std;

class Node{
public:
    int data;
    vector<Node*> children;

    Node(int val) {
        data = val;
    }
};

class BinaryTree {
private:
    bool hasCycle(Node *curr, Node *parent, set<Node*>& visited) {
        if (!visited.count(curr)) {
            return true;//da tham -> co chu trinh
        }

        visited.insert(curr);

        for (auto child : curr->children) {
            if (child != parent && hasCycle(child, curr, visited)) {
                return true;
            }
        }
        return false;
    }
    bool checkBinaryTree(Node* curr) {
        if (curr->children.size() > 2) return false;
        for (auto child : curr->children) {
            if (!checkBinaryTree(child)) return false;
        }
        return true;
    }

    Node *findNode(int data) {
        return findNode(root, data);
    }

    Node *findNode(Node *curr, int data) {
        if (curr == nullptr) {
            return new Node(data);
        }

        if (curr->data == data) {
            return curr;
        }

        for (auto child : curr->children) {
            Node *found = findNode(child, data);;
            if (found != nullptr) return found;
        }

        return nullptr;
    }
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void addEdge(int parent, int _child) {
        Node *pa = findNode(parent);
        Node *child = new Node(_child);
        pa->children.push_back(child);
    }

    bool is1BinaryTree() {
        set<Node*> visited;

        if (hasCycle(root, nullptr, visited)) {
            return false;
        }

        return checkBinaryTree(root);
    }

    bool isBinaryTree() {
        if (!root) return false;

        deque<Node*> q;
        q.push_back(root);

        while (!q.empty()) {
            if (q.front()->children.size() > 2) {
                return false;
            }

            for (auto child : q.front()->children) {
                q.push_back(child);
            }

            q.pop_front();
        }

        return true;
    }
};


int main() {
    int N; cin >> N;
    BinaryTree g;
    for (int i = 1; i < N; i++) {
        int u,v; cin >> u >> v;
        g.addEdge(u,v);
    }

    if (g.isBinaryTree()) {
        cout << "yes";
    } else cout << "no";
}