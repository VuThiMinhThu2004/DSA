#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int direction(int p, int q, int r)
{
    int val = (q - p) * (r - q);
    if (val == 0)
    {
        return 0;
    }
    else if (val > 0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

bool inALine(int p, int q, int r)
{
    if (q >= min(p, r) && q <= max(p, r))
    {
        return true;
    }
    return false;
}

bool doEdgesIntersect(int u1, int v1, int u2, int v2)
{
    int direction1 = direction(u1, v1, u2);
    int direction2 = direction(u1, v1, v2);
    int direction3 = direction(u2, v2, u1);
    int direction4 = direction(u2, v2, v1);

    if (direction1 != direction2 && direction3 != direction4)
    {
        return true;
    }

    if (direction1 == 0 && inALine(u1, u2, v1))
    {
        return true;
    }
    if (direction2 == 0 && inALine(u1, v2, v1))
    {
        return true;
    }
    if (direction3 == 0 && inALine(u2, u1, v2))
    {
        return true;
    }
    if (direction4 == 0 && inALine(u2, v1, v2))
    {
        return true;
    }

    return false;
}


int Parallel(const vector<vector<int>> &graph)
{
    int count = 0;
    for (int u = 0; u < graph.size(); u++)
    {
        for (int v : graph[u])
        {
            for (int x = u + 1; x < graph.size(); x++)
            {
                for (int y : graph[x])
                {
                    if (u != x && u != y && v != x && v != y)
                    {
                        if (doEdgesIntersect(u, v, x, y))
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> graph;
    int n;
    cout << "Nhập số cạnh của đồ thị";
    cin >> n;
    cout << "Nhập tạo độ các cạnh";
    while (n != 0)
    {
        int a, b;
        cin >> a >> b;
        graph.push_back(vector<int>{a, b});
        n--;
    }

    int parallelEdgesCount = Parallel(graph);
    cout << "Number of parallel edges: " << parallelEdgesCount << endl;

    return 0;
}