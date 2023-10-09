#include "bits/stdc++.h"
using namespace std;

map<int, string> mp;

int countNo(int n) {
    int res = 0;
    while (n) {
        res++;
        n/=10;
    }
    return res;
}
int main() {
    queue<string> q;
    string s;
    while (cin >> s) {
        q.push(s);
    }
    while (!q.empty()) {      
        string s = q.front();
        q.pop();
        
        if (s.substr(0,6) == "Insert") {
            int Id;
            sscanf(s.c_str(), "Insert(%d,%[^,],%[^)])", &Id);
            int pos = 8+countNo(Id);
            //cout << Id << " " << pos << endl;
            mp[Id] = s.substr(pos, (int)(s.size()-pos-1));
        } else if (s.substr(0,5) == "Infor") {
            int Id;
            sscanf(s.c_str(), "Infor(%d)", &Id);
            if (mp[Id].size() > 0)
                cout << mp[Id] << endl;
            else cout << "NA,NA" << endl;
        } else if (s.substr(0,6) == "Delete") {
            int Id;
            sscanf(s.c_str(), "Delete(%d)", &Id);
            mp[Id] = "";
        }
    }
}

/*
Insert(1,Tuan,K61CS)
Insert(2,Vinh,K43C)
Infor(3)
Infor(2)
Delete(2)
Infor(2)
*/