#include "bits/stdc++.h"
using namespace std;

struct Node {
    int value;
    Node *left = nullptr;
    Node *right = nullptr;
    
    Node(){}

    Node(int value) {
        this->value = value;
    }
};

class BinaryTree{
public:
    Node *insert(Node *root, int value) {
        if (!root) {
            return new Node(value);
        } 
        
        Node *curr = nullptr;
        if (root->value >= value) {
            curr = insert(root->left, value);
            root->left = curr;
        } else {
            curr = insert(root->right, value);
            root->right = curr;
        }         
        return root;
    }

    void Preorder(Node *root) {
        if (root == nullptr) return;
        cout << root->value << " ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Postorder(Node *root) {
        if (!root) return;
        Postorder(root->left);
        Postorder(root->right);
        cout << root->value << " ";
    }

    void Inorder(Node *root) {
        if (!root) return;
        Inorder(root->left);
        cout << root->value << " ";
        Inorder(root->right);
    }

    int getHeight(Node *root) {
        if (!root) return -1;
        int Hleft = getHeight(root->left);
        int Hright = getHeight(root->right);
        return max(Hleft, Hright) + 1;
    }    

    void topView(Node * root) {
        queue<pair<int,Node*>> q;
        q.push(make_pair(0, root));
        map<int,Node*> ans;

        for(auto i = q.front(); !q.empty(); q.pop(), i = q.front()) {
            if(!i.second) continue;
            ans.insert(i);
            q.push(make_pair(i.first + 1, i.second->right));
            q.push(make_pair(i.first - 1, i.second->left));
        }

        for(auto i: ans) {
            cout << i.second->value << " ";
        }
    }

    
    void levelOrder(Node * root) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node* root = q.front();
            q.pop();
            if (!root) continue;
            cout << root->value << ' ';
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }
    }

    void print(Node *root) {
        if (!root) return;
        cout << root->value << " ";
        print(root->left);
        print(root->right);
    }
    
    //LCA
    Node * lca(Node * root, int v1,int v2) {
        if(root == nullptr) return nullptr;
        int data = root->value;
        if(v1 < data && v2 < data) return lca(root->left, v1, v2);
        if(v1 > data && v2 > data) return lca(root->right, v1, v2);
        return root;
    }
    //lower command as.. LCA
    bool dfs(Node *root, int data) {
        if (!root) return false;
        if (root->value == data) return true;
        
        if (data < root->value) 
            return dfs(root->left, data);
            
        return dfs(root->right, data);        
    }
    
    bool check(Node *root, int v1, int v2) {
        if (!root) return false;
        if (dfs(root, v1) == true && dfs(root, v2) == true) {
            return true;
        }
        return false;
    }
    int xm = 0;
    
    void kt(Node *root, int v1, int v2) {
        if (!root) return;
        if (check(root, v1, v2)) xm = root->value;
        
        if (v1 > root->value && v2 > root->value) {
            kt(root->right, v1,v2);
        } else {
            //if (v1 < root->value && v2 < root->value) {
            kt(root->left, v1, v2);
        }
    }
};

int main() {
    BinaryTree g;
    Node *root = nullptr;

    int n,data; cin >> n;
    while (n--) {
        cin >> data;
        root = g.insert(root, data);
    }
    g.Preorder(root);
    return 0;
}

/*\
15
1 14 3 7 4 5 15 6 13 10 11 2 12 8 9

bool final = true;
    void check(Node *root) {
        if (!root) return;
        if (root->data < root->left->data || root->data > root->right->data) {
            final = false;
        } else if (root->data >= root->left->data) {
            check(root->left);
        } else check(root->right);
    }
    void print(Node *root) {
        if (!root) return;
        cout << root->data << " ";
        print(root->left);
        print(root->right);
    }
*/