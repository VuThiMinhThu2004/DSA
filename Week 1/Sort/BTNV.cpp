#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 5e4 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

vector<int> v(MAXN);

//Selection Sort
  void display(double step, int N)
  {
    cout << "step " << step << ": ";
    ff(i, 1, N)
      cout << v[i] << " ";
    cout << "\n";
  }

  void Selection_sort(int N)
  {
    display(0, N);

    ff(i, 1, N - 1)
    {
      int pos = i;

      ff(j, i + 1, N)
        if (v[j] < v[pos])
          pos = j;
      
      
      swap(v[i], v[pos]);
      display(i, N);
    }
  }
//End Selection sort

//Insertion sort
  void Insertion_sort(int N)
  {
    // cout << 1 << "\n";
    display(1, N);

    ff(i, 2, N)
    {
      int pos = i;

      Rep(j, i - 1, 1)
      {
        if (v[j] > v[pos])
          swap(v[pos], v[j]),
          pos--;
      }
      // cout << i << "\n";
      display(i, N);
    }
  }
//End insertion sort

//Bubble sort
  void Bubble_sort(int N)
  {
    display(0, N);

    bool any_swap = true;
    int step = 1;

    while(any_swap)
    {
      any_swap = false;
      double x = step + 0.0;
      cout << "step" << step << ":\n";

      ff(i, 1, N - 1)
      {
        if (v[i] > v[i + 1])
          swap(v[i], v[i + 1]),
          any_swap = true;
        
        x += 0.1;
        cout << "  ";
        display(x, N);
      }

      step++;
      
    }
  }
//end Bubble sort

//Merge Sort
  deque<int> F1, F2;

  int get_value()
  {
    int flag, ans;

    if (F1.empty())
      flag = 2;
    else if (F2.empty())
      flag = 1;
    else
    {
      if (F1.front() <= F2.front())
        flag = 1;
      else
        flag = 2;
    }

    if (flag == 1)
      ans = F1.front(),
      F1.pop_front();
    else
      ans = F2.front(),
      F2.pop_front();
    
    return ans;
  }

  void Merge(int l, int r)
  {
    int mid = (l + r)/2;
    
    ff(i, l, mid)
      F1.push_back(v[i]);
    ff(i, mid + 1, r)
      F2.push_back(v[i]);
    
    ff(i, l, r)
      v[i] = get_value();

  }

  void Merge_sort(int l, int r)
  {
    if (l == r)
    {
      cout << "index" << " " << l << " " << v[l] << "\n";
      return;
    }
    int mid = (l + r)/2;

    Merge_sort(l, mid);
    Merge_sort(mid + 1, r);
    Merge(l, r);

    cout << "range" << " " << l << " "  << r << "\n";
    ff(i, l, r)
      cout << v[i] << " ";
    cout << "\n";
  }
//End Merge Sort


//Quick sort

  void Quick_sort(int l, int r)
  {
    if (r <= l)
    {
      if (r == l)
        cout << l << " "  << v[l] << "\n";
      return;
    }
    
    int target = v[r], id = -1;
    ff(i, l, r - 1)
    {
      if (v[i] > target && id == -1)
        id = i;
      else if (v[i] <= target && id > 0)
      {
        swap(v[i], v[id]);
        id++;
      }
    }

    cout << "pivot " << target << "\n";
    cout << "left_array ";
    ff(i, l, id - 1)
      cout << v[i] << " ";
    cout << "\n" << "right_array ";
    ff(i, max(id + 1, 1), r)
      cout << v[i] << " ";
    cout << "\n";

    if (id == -1)
      Quick_sort(l, r - 1);
    else
    {
      swap(v[r], v[id]);
      Quick_sort(l, id - 1);
      Quick_sort(id + 1, r);
    }

  }
//End Quick sort


void solve()
{
  int N; cin >> N;

  ff(i, 1, N)
    cin >> v[i];

   Selection_sort(N);
   cout << endl << "INSERTION SORT" << endl;
   //Insertion_sort(N);

  // cout << endl << "BUBBLE SORT" << endl;
  //Bubble_sort(N);
  // Merge_sort(1, N);
  // Quick_sort(1, N);
  // display(N);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}