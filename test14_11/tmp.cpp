#include <bits/stdc++.h>

using namespace std;

int f_a[35], f_b[35];

int solve(string s)
{
    int res = 0;
    for (int id_1 = 0; s[id_1] != '\0'; id_1++)
    {
        for (int id_2 = id_1 + 1; s[id_2] != '\0'; id_2++)
        {
            for (int i = 'a'; i <= 'z'; i++)
                f_a[i - 'a'] = f_b[i - 'a'] = 0;
            for (int k = 0; s[id_1 + k] != '\0' && s[id_2 + k] != '\0'; k++)
            {
                f_a[s[id_1 + k] - 'a']++;
                f_b[s[id_2 + k] - 'a']++;

                bool check = true;
                for (int i = 'a'; i <= 'z'; i++)
                {
                    if (f_a[i - 'a'] != f_b[i - 'a'])
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                    res++;
            }
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}