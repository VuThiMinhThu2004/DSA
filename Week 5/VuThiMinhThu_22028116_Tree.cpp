#include <bits/stdc++.h>

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

    vector<Node*> nodeChild;

public:
    Node() {}

    Node(Node* fatherNode, int data) {
        this->fatherNode = fatherNode;
        this->data = data;
    }

    Node(int data) {
        this->fatherNode = NULL;
        this->data = data;        
    }
    // Các hàm khởi tạo khác nếu cần thiết

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        // ...
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Tree(int data) {
        root = new Node(data);
    }

    Node *search(int data) {
        if (!root || !data) {
            return nullptr;
        }

        deque<Node*> q;

        q.push_back(root);

        while (!q.empty()) {
            if (q.front()->data == data) {
                return q.front();
            }

            for (auto child : q.front()->nodeChild) {
                q.push_back(child);
            }
            q.pop_front();
        }

        return nullptr;
    }
    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        if(!root) return false;

        Node* fatherNode = search(father);
        
        if(!fatherNode) return false;

        for (auto child : fatherNode->nodeChild) {
            if (child->data == data) {
                return false;
            }
        }

        Node* newChild = new Node(fatherNode, data);
        fatherNode->nodeChild.push_back(newChild);

        return true;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int Remove(Node *root) {
        int count = 0;

        for (auto child : root->nodeChild) {
            count += Remove(child);
        }

        delete root;
        
        return count + 1;
    }

    int Remove(int data) {
        if (!root) return 0;

        Node *deleteNode = search(data);

        if (!deleteNode) return 0;

        if (deleteNode->fatherNode != nullptr) {
            deleteNode->fatherNode->nodeChild.erase(remove(deleteNode->fatherNode->nodeChild.begin(),deleteNode->fatherNode->nodeChild.end(),deleteNode),
            deleteNode->fatherNode->nodeChild.end());
        }
        return Remove(deleteNode);
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node *root) {
        cout << root->data << " ";
        for (auto child : root->nodeChild) {
            preorder(child);
        }
    }

    void preorder() {
        if (root == nullptr) return;
        preorder(root);
        cout << "\n";
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node *root) {
        for (auto child : root->nodeChild) {
            postorder(child);
        }

        cout << root->data << " ";
    }

    void postorder() {
        if (!root)  return;
        preorder(root);
        cout << "\n";
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        if (!root) return false;

        deque<Node*> q;
        q.push_back(root);

        while (!q.empty()) {
            if (q.front()->nodeChild.size() > 2) {
                return false;
            }

            for (auto child : q.front()->nodeChild) {
                q.push_back(child);
            }

            q.pop_front();
        }

        return true;
    }

    bool isBinarySearchTree(Node *root, int childMin, int childMax) {
        if (root->data < childMin || root->data > childMax) {
            return false;
        }
        if (root->nodeChild.empty()) {
            return true;
        }
        bool childLeft = (root->nodeChild[0], childMin, root->data);
        if (root->nodeChild.size() == 2) {
            return childLeft && isBinarySearchTree(root->nodeChild[1], root->data, childMax);
        }
        return childLeft;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
        if (!isBinaryTree())    return false;
        return isBinarySearchTree(root, -1000000000, 1000000000);
    }

    bool isMaxHeapTree(Node *root, int heapMax) {
        if (root->data > heapMax) return false;

        for (auto child : root->nodeChild) {
            if (!isMaxHeapTree(child,root->data)) {
                return false;
            }
        }
        return true;
    }
    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {
        if (root == nullptr)    return true;
        return (isBinaryTree() && isMaxHeapTree(root, 1e9));
    }

    void inorder(Node *root) {
        if (!root->nodeChild.empty()) {
            inorder(root->nodeChild[0]);
        }

        cout << root->data << " ";

        if (root->nodeChild.size() == 2)
            inorder(root->nodeChild[1]);
    }
    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder() {
        if (isBinaryTree()) {
            inorder(root);
        }
        else return;
    }

    // Hàm trả về độ cao của cây
    int height(Node *head) {
        if (root->nodeChild.empty()) return 0;

        int res = 0;
        for (auto child : root->nodeChild) {
            res = max(res, height(child));
        }
        return res + 1;
    }

    int height() {
        if (root != nullptr) return height(root);
        return -1;
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        if (!root) return false;

        int cnt[1005];
        memset(cnt, -1, sizeof(cnt));

        cnt[root->data] = 0;
        deque<Node*> q;

        q.push_back(root);

        while (!q.empty()) {
            if (q.front()->data == data) {
                return cnt[data];
            }

            for (auto child : q.front()->nodeChild) {
                cnt[child->data] = cnt[q.front()->data] + 1;
                q.push_back(child);
            }
            q.pop_front();
        }
        return -1;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves() {
        if (!root) return -1;

        int res = 0;

        deque<Node*> q;

        q.push_back(root);

        while (!q.empty()) {
            if (q.front()->nodeChild.empty()) {
                ++res;
            }

            for (auto child : q.front()->nodeChild) {
                q.push_back(child);
            }
            q.pop_front();
        }
        return res;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax() {
        if (!root) return INT_MIN;

        int res = INT_MIN;

        deque<Node*> q;
        q.push_back(root);

        while (!q.empty()) {
            res = max(res, q.front()->data);

            for (auto child : q.front()->nodeChild) {
                q.push_back(child);
            }
            q.pop_front();
        }

        return res;
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        if (!root) return 0;

        int res = 0;

        deque<Node*> q;
        q.push_back(root);

        while (!q.empty()) {
            res = max((int) (q.front()->nodeChild.size()), res);

            for (auto child : q.front()->nodeChild) {
                q.push_back(child);
            }

            q.pop_front();
        }

        return res;
    }
};

void Test() {

    Tree g(0);
    
    g.insert(5, 1);
    g.insert(2, 3);
    g.insert(1, 7);
    g.insert(1, 18);
    g.insert(2, 11);
    g.insert(5, 10);
    g.insert(3, 9);
    g.insert(4, 15);
    g.insert(23, 33);
    g.insert(31, 17);

    g.preorder();
    cout << g.Remove(1) << "\n";
    g.preorder();
    g.postorder();
    cout << "isBinaryTree: " << g.isBinaryTree() << "\n";
    cout << "isBinarySearchTree: " << g.isBinarySearchTree() << "\n";
    cout << "isMaxHeapTree: " << g.isMaxHeapTree() << "\n";
    cout << "height = " << g.height() << "\n";
    cout << "depth = " << g.depth(29) << "\n";
    cout << "numOfLeaves = " << g.numOfLeaves() << "\n";
    cout << "childMax = " << g.findMax() << "\n";
    cout << "node max child = " << g.findMaxChild() << "\n";
}
int main() {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại

    Test();
    return 0;
}