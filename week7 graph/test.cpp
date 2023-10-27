#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node* fatherNode = nullptr;

    Node(Node* fatherNode, int data) {
        this->fatherNode = fatherNode;
        this->data = data;
    }

    Node(int data) {
        this->fatherNode = NULL;
        this->data = data;        
    }
};

class Tree {
private: 
    Node* root = nullptr;

public:
    Tree() {
        // ...
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Tree(int data) {
        root = new Node(data);
    }

    Node *search(Node *root, int data) {
        if (!root || !data) {
            return nullptr;
        }

        if (data == root->data) {
            return root;
        } else {
            Node *ok = search(root->left, data);
            if (ok == nullptr)
                return search(root->right, data);
        }
        

        return nullptr;
    }
    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        if(!root) return false;

        Node* fatherNode = search(root, father);
        
        if(!fatherNode) return false;

        if (fatherNode->left == nullptr) {
            fatherNode->left = new Node(data);
        } 
        else if (fatherNode->right == nullptr) {
            fatherNode->right = new Node(data);
        }

        return true;
    }
};
int main() {

}
/*
2
{()[]}
([)]
*/



/*
cau 1 : linklist, stack, queue
cau 2 : set map hash 
2 cau cuoi diem cao hon
cau 3 : tree 
cau 4 : graph 

15 cau trac nghiem
*/
