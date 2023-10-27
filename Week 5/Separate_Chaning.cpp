#include "bits/stdc++.h"
using namespace std;
const int P = 1e6 + 3;

class hashTable {
private:
    vector<pair<int,int>> h[P];

    int getHash(int key) {
        //cho 1 key, tra lai Hash value la key%P;
        return key%P;
    }
public:
    void insert(int key, int value) {
        int hkey = getHash(key);
        for (auto p : h[hkey]) {
            if (p.first == key) {
                return;//key da ton tai trong hashTable, ta bo qua
            }
        }
        //them (key,value) vao hashTable
        h[hkey].emplace_back(key, value);
    }

    int find(int key) {
        int hkey = getHash(key);
        for (auto p : h[hkey]) {
            if(p.first == key) {
                //p.second = p.value;
                return p.second;//ton tai key tr hashTable
            }
        }
        return 0;//khong tim thay
    }

};



//gia su bang bam chi tra ve gia tri tu [1;19]
vector<string> hashTable[20];
int hashTableSize = 20;

int hashFunc(string s) {
    int sum = 0;
    for (auto it : s) {
        sum += (it - 'a');
    }
    return sum % 17;
}

void insert(string s) {
    //Compute the index using Hash Function
    int index = hashFunc(s);
    //Insert the element in the linked list at the particular index
    hashTable[index].push_back(s);
}

void search(string s) {
    //Compute the index by using the hash function
    int index = hashFunc(s);
    //Search the linked list at that specific index
    for (int i = 0; i < hashTable[index].size(); i++) {
        if (hashTable[index][i] == s) {
            cout << s << " is found!" << endl;
            return;
        }
    }
    cout << s << " is not found!" << endl;
}

int main() {
    

}