#include "bits/stdc++.h"
using namespace std;

class Stack {
private:
    struct Node {
        int value;
        int max_value;
        Node *prev = nullptr;

        Node() {}
        
        Node(int _value) {
            value = _value;
        }
    };


public:
    Node *top = nullptr;

    int getTop() {
        return top->value;
    }

    int max_value() {
        if (!top) {
            throw exception();//tra ve 1 ngoai le
        }
        return top->max_value;
    }

    void push(int value) {
        Node *newNode = new Node(value);
        if (top) {
            newNode -> max_value = max(top->max_value, value);
        } else {//empty()
            newNode -> max_value = value;
        }
        newNode->prev = top;
        top = newNode;//update top
    }

    void pop() {
        if (top) {
            top = top->prev;
        }
    }
};
int main() {

}