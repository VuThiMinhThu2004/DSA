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

//Consolidate 2 Queue -> Stack

struct Node
{
  int data;
  Node* next;
};

class Queue
{
  private:
    Node *head, *tail;
    int length = 0;
  
  public:
    bool is_empty()
    {
      return (length == 0);
    }

    int get_length()
    {
      return length;
    }

    int get_top()
    {
      if (is_empty())
        return -INF;

      return head->data;
    }

    void Push(int val)
    {
      Node* tmp = new Node;
      tmp->data = val;
      tmp->next = NULL;

      length++;

      if (length == 1)
      {
        head = tmp;
        tail = tmp;
        return;
      }

      tail->next = tmp;
      tail = tmp;
    }

    void Pop()
    {
      if (is_empty())
        return;
      
      length--;

      Node* tmp = head->next;
      delete head;
      head = tmp;
    }
};

Queue storage1, storage2;

int Remove()
{
  while(storage1.get_length() > 1)
    storage2.Push(storage1.get_top()),
    storage1.Pop();
  
  int ans = storage1.get_top();
  storage1.Pop();

  while(!storage2.is_empty())
    storage1.Push(storage2.get_top()),
    storage2.Pop();

  return ans;
}

void solve()
{
  int T; cin >> T;

  while(T--)
  {
    string txt;
      cin >> txt;

      if (txt == "push")
      {
        int val; cin >> val;
        storage1.Push(val);
      }
      else  
        cout << Remove() << " ";
  }

  
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}

/*
#include "iostream"
#include "queue"
using namespace std;

int main() {
    queue<string> q;
    int n; cin >> n;
    cin.ignore();

    while (n--) {
        string s; getline(cin,s);
        q.push(s);
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}
*/