#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;

public:
    Node() {
        fatherNode = nullptr;
        firstChild = nullptr;
    }

    Node (int data) {
        this->data=data;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Node(Node *fatherNode, int data) {
        this->data = data;
        this->fatherNode = fatherNode;
    }
    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        root = nullptr;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Node *search(Node *root, int key) {
        if (root == nullptr) return root;
        if (root->data == key) return root;
        Node * findChild = search(root->firstChild, key);
        if (findChild == nullptr)
            return search(root->nextSibling, key);
        else return findChild;
    }
    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    void insert(int father, int data) {
        if (root == nullptr) {
            root = new Node(father);
            Node *newNode = new Node(data);
            root->firstChild = newNode;
            return;
        }
        insert(root, data, father);
    }

    void insert(Node* node, int value, int father) {
        if (node == nullptr) {
            return;
        }
        if (node->data == father) {
            if (node->firstChild == nullptr) {
                node->firstChild = new Node(value);
            } else {
                node->nextSibling = new Node(value);
            }
        } else {
            insert(node->firstChild, value, father);
            insert(node->nextSibling, value, father);
        }
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {

    }

    Node *remove(Node *root, int data) {

    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node *root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->firstChild);
        preorder(root->nextSibling);
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node *root) {
        if (root == nullptr) return;
        postorder(root->firstChild);
        cout << root->data << " ";
        postorder(root->nextSibling);
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree(Node *root) {
        
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree(Node *root) {
        if (root == nullptr) return true;
        if(root->firstChild != nullptr && root->nextSibling->data > root->data ||
           root->nextSibling != nullptr && root->nextSibling->data < root->data) {
            return false;
        }
        return isBinarySearchTree(root->firstChild);
        return isBinarySearchTree(root->nextSibling);    
    }

    
    bool isMaxHeapTree(Node *root, int Max) {
        if (root->data > Max) return false;
        if (root->firstChild->data > Max || root->nextSibling) return false;
        return isMaxHeapTree(root->firstChild, Max);
        return isMaxHeapTree(root->nextSibling, Max);
        return true;
    }
    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {
        if (!isBinaryTree(root)) return false;
        if (root == nullptr) return true;
        return isMaxHeapTree(root, 1000000000);
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder(Node *root) {
        if (root == nullptr) return;
        inorder(root->firstChild);
        cout << root->data << " ";
        inorder(root->nextSibling);
    }

    // Hàm trả về độ cao của cây
    int height(Node *root) {
        if (root == nullptr) return 0;
        int leftH = height(root->firstChild);
        int rightH = height(root->nextSibling);
        return max(leftH, rightH) + 1;
    }

    // Hàm trả về độ sâu của một Node
    int getDepth(Node *root) {
        if (root == nullptr) return 0;
        int leftH = height(root->firstChild);
        int rightH = height(root->nextSibling);
        return max(leftH, rightH) + 1;
    }

    int depth(int data) {
        Node *node = search(root, data);
        return getDepth(node);
    }

    // Hàm đếm số lượng lá
    int numOfLeaves(Node *root) {
        if (root->firstChild == nullptr && root->nextSibling == nullptr) return 1;
        return numOfLeaves(root->firstChild) + numOfLeaves(root->nextSibling);
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax(Node *root, int xmax) {
        if (root != nullptr) {
            xmax = max(root->data, xmax);
            xmax = max(xmax, findMax(root->firstChild, xmax));
            xmax = max(xmax, findMax(root->nextSibling, xmax));
        }
        return xmax;
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild(Node *root) {
        if (root == nullptr) return 0;
        else {
            int cnt = 1;
            while (root->nextSibling != nullptr) {
                root = root->nextSibling;
                cnt++;
            }
            return cnt;
        }
        return findMaxChild(root->firstChild);
    }
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}