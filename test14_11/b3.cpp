#include "bits/stdc++.h"
using namespace std;

int main() {
    string s; getline(cin,s);
    stringstream ss(s);
    string temp = "";
    stack<string> v;
    while(ss >> temp) {
        v.push(temp);
    }
    while (!v.empty()) {
        cout << v.top() << " ";
        v.pop();
    }
     return 0;   
}