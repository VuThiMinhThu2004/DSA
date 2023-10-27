#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 1e5 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;


class Node {
    int data;
    
    Node* fatherNode;

    vector<Node*> nodeChild;

public:
    Node() {
        // ...
    }

    Node(int data, Node* fatherNode) {
        this->data = data;
        this->fatherNode = fatherNode;
    }

    Node(int data) {
        this->data = data;
        this->fatherNode = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root = NULL;
    int depth[MAXN];
public:
    Tree(int data) {
        root = new Node(data);

    }
    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    Node* findNode(int value) {
        
        deque<Node*> storage;

        storage.push_back(root);

        while(!storage.empty()) {

            if (storage.front()->data == value) {
                return storage.front();
            }

            for(auto child : storage.front()->nodeChild) {
                storage.push_back(child);
            }

            storage.pop_front();
        }

        return NULL;
    }

    bool insert(int father, int data) {

        if (root == NULL) {
            return false;
        }

        Node* fatherNode = findNode(father);

        if (fatherNode == NULL) {
            return false;
        }

        for(auto child : fatherNode->nodeChild) {
            if (child->data == data) {
                return false;
            }
        }

        Node* newChild = new Node(data, fatherNode);
        fatherNode->nodeChild.push_back(newChild);

        return true;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int Remove(Node* head) {

        int ans = 0;

        for(auto child : head->nodeChild) {
            ans += Remove(child);
        }

        delete head;

        return ans + 1;
    }

    int Remove(int data) {
        if (root == NULL) {
            return 0;
        }

        Node* deleteNode = findNode(data);

        if (deleteNode == NULL) {
            return 0;
        }

        if (deleteNode->fatherNode != NULL) {

            deleteNode->fatherNode->nodeChild.erase(
                remove(deleteNode->fatherNode->nodeChild.begin(), deleteNode->fatherNode->nodeChild.end(), deleteNode), 
                deleteNode->fatherNode->nodeChild.end());
        }

        return Remove(deleteNode);
    }

    void preoderTraversal(Node* head) {

        cout << head->data << " ";
        
        for(auto child : head->nodeChild) {
            preoderTraversal(child);
        }
    }
    // Hàm in ra các Node theo thứ tự preorder
    void preorder() {

        if (root == NULL) {
            return;
        }

        preoderTraversal(root);
        cout << "\n";
    }

    void postorderTraversal(Node* head) {

        for(auto i : head->nodeChild) {
            postorderTraversal(i);
        }

        cout << head->data << " ";
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder() {
        if (root == NULL) {
            return;
        }
        postorderTraversal(root);
        cout << "\n";
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {

        if (root == NULL) {
            return false;
        }
        deque<Node*> storage;
        storage.push_back(root);

        while(!storage.empty()) {

            if (storage.front()->nodeChild.size() > 2) {
                return false;
            }

            for(auto child : storage.front()->nodeChild) {
                storage.push_back(child);
            }

            storage.pop_front();
        }

        return true;
    }

    bool isBinarySearchTree(Node* head, int MIN, int MAX) {

        if (head->data >= MAX || head->data <= MIN) {
            return false;
        }

        if (head->nodeChild.empty()) {
            return true;
        }

        bool tmp1 = (head->nodeChild[0], MIN, head->data);

        if (head->nodeChild.size() == 2) {
            return tmp1 && isBinarySearchTree(head->nodeChild[1], head->data, MAX);
        }

        return tmp1;
    }
    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {

        if (!isBinaryTree()) {
            return false;
        }

        return isBinarySearchTree(root, -INF, INF);
    }

    bool isMaxHeapTree(Node* head, int MAX) {

        if (head->data > MAX) {
            return false;
        }

        for(auto child : head->nodeChild) {

            if (!isMaxHeapTree(child, head->data)) {
                return false;
            }
        }

        return true;
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {

        if (root == NULL) {
            return true;
        }

        if (!isBinaryTree()) {
            return false;
        }

        return isMaxHeapTree(root, INF);
    }

    void inorder(Node* head) {

        if (!head->nodeChild.empty()) {
            inorder(head->nodeChild[0]);
        }

        cout << head->data << " ";

        if (head->nodeChild.size() == 2) {
            inorder(head->nodeChild[1]);
        }
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder() {

        if (!isBinarySearchTree()) {
            return;
        }

        inorder(root);
        cout << "\n";
    }

    int height(Node* head) {

        if (head->nodeChild.empty()) {
            return 0;
        }

        int ans = 0;
        for(auto child : head->nodeChild) {
            ans = max(ans, height(child));
        }

        return ans + 1;
    }
    // Hàm trả về độ cao của cây
    int height() {

        if (root == NULL) {
            return -1;
        }

        return height(root);
    }

    // Hàm trả về độ sâu của một Node
    int countDepth(int data) {

        if (root == NULL) {
            return -INF;
        }

        ff(i, 0, MAXN - 5) {
            depth[i] = -1;
        }

        depth[root->data] = 0;

        deque<Node*> storage;
        storage.push_back(root);

        while(!storage.empty()) {

            if (storage.front()->data == data) {
                return depth[data];
            }

            for(auto child: storage.front()->nodeChild) {
                depth[child->data] = depth[storage.front()->data] + 1;
                storage.push_back(child);
            }

            storage.pop_front();
        }

        return -1;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves() {
        if (root == NULL) {
            return -INF;
        }

        int ans = 0;

        deque<Node*> storage;
        storage.push_back(root);

        while(!storage.empty()) {

            if (storage.front()->nodeChild.empty()) {
                ans++;
            }

            for(auto child: storage.front()->nodeChild) {
                storage.push_back(child);
            }

            storage.pop_front();
        }

        return ans;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax() {

        if (root == NULL) {
            return -INF;
        }

        int ans = -INF;

        deque<Node*> storage;
        storage.push_back(root);

        while(!storage.empty()) {

            ans = max(ans, storage.front()->data);

            for(auto child: storage.front()->nodeChild) {
                storage.push_back(child);
            }

            storage.pop_front();
        }

        return ans;

    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        if (root == NULL) {
            return -INF;
        }

        int ans = root->data;

        deque<Node*> storage;
        storage.push_back(root);

        while(!storage.empty()) {

            if (storage.front()->nodeChild.size() > ans) {
                ans = storage.front()->data;
            }

            for(auto child: storage.front()->nodeChild) {
                storage.push_back(child);
            }

            storage.pop_front();
        }

        return ans;
    }
};

void randomTest() {

    Tree OwO(0);
    
    OwO.insert(0, 1);
    OwO.insert(0, 2);
    OwO.insert(0, 3);
    OwO.insert(0, 5);
    OwO.insert(1, 7);
    OwO.insert(1, 4);
    OwO.insert(1, 18);
    OwO.insert(2, 11);
    OwO.insert(3, 25);
    OwO.insert(3, 26);
    OwO.insert(5, 14);
    OwO.insert(5, 10);
    OwO.insert(4, 27);
    OwO.insert(4, 9);
    OwO.insert(4, 6);
    OwO.insert(26, 29);
    OwO.insert(26, 32);
    OwO.insert(26, 31);
    OwO.insert(31, 24);
    OwO.insert(31, 17);

    OwO.preorder();
    cout << OwO.Remove(1) << "\n";
    OwO.preorder();
    OwO.postorder();
    cout << OwO.isBinaryTree() << "\n";
    cout << OwO.isBinarySearchTree() << "\n";
    cout << OwO.isMaxHeapTree() << "\n";
    cout << OwO.height() << "\n";
    cout << OwO.countDepth(29) << "\n";
    cout << OwO.numOfLeaves() << "\n";
    cout << OwO.findMax() << "\n";
    cout << OwO.findMaxChild() << "\n";
}

void binarysearchtreeTest() {
    Tree OwO(42);

    OwO.insert(42, 24);
    OwO.insert(42, 49);
    OwO.insert(24, 4);
    OwO.insert(24, 26);
    OwO.insert(4, 1);
    OwO.insert(4, 6);
    OwO.insert(6, 5);
    OwO.insert(6, 10);
    OwO.insert(10, 7);
    OwO.insert(26, 25);
    OwO.insert(49, 47);
    OwO.insert(47, 46);
    OwO.insert(49, 53);
    OwO.insert(53, 50);
    OwO.insert(53, 99);
    OwO.insert(99, 63);
    OwO.insert(63, 54);

    OwO.preorder();
    cout << OwO.Remove(24) << "\n";
    OwO.preorder();
    OwO.postorder();
    cout << OwO.isBinaryTree() << "\n";
    cout << OwO.isBinarySearchTree() << "\n";
    cout << OwO.isMaxHeapTree() << "\n";
    cout << OwO.height() << "\n";
    cout << OwO.countDepth(46) << "\n";
    cout << OwO.numOfLeaves() << "\n";
    cout << OwO.findMax() << "\n";
    cout << OwO.findMaxChild() << "\n";
}

void maxheaptreeTest() {
    Tree OwO(99);
    
    OwO.insert(99, 25);
    OwO.insert(99, 42);
    OwO.insert(25, 10);
    OwO.insert(25, 19);
    OwO.insert(42, 30);
    OwO.insert(42, 40);
    OwO.insert(10, 9);
    OwO.insert(10, 4);
    OwO.insert(19, 15);
    OwO.insert(19, 17);
    OwO.insert(30, 25);
    OwO.insert(30, 24);
    OwO.insert(40, 37);
    OwO.insert(40, 36);
    OwO.insert(9, 5);
    OwO.insert(9, 6);
    OwO.insert(4, 1);
    OwO.insert(4, 2);
    OwO.insert(15, 10);
    OwO.insert(15, -7);
    OwO.insert(17, -9);
    OwO.insert(17, -25);   

    OwO.preorder();
    cout << OwO.Remove(25) << "\n";
    OwO.preorder();
    OwO.postorder();
    cout << OwO.isBinaryTree() << "\n";
    cout << OwO.isBinarySearchTree() << "\n";
    cout << OwO.isMaxHeapTree() << "\n";
    cout << OwO.height() << "\n";
    cout << OwO.countDepth(24) << "\n";
    cout << OwO.numOfLeaves() << "\n";
    cout << OwO.findMax() << "\n";
    cout << OwO.findMaxChild() << "\n"; 
}


int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);

    randomTest();
    //binarysearchtreeTest();
    //maxheaptreeTest();

    return 0;
}
