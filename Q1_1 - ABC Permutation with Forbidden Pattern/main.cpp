#include <iostream>
#include <set>

using namespace std;

set<string> forbidden;
set<string> result;

void permute(int N, int n_a, int n_b, int n_c, string tmp, string last_char)
{
    if (tmp.length() == N)
    {
        result.insert(tmp);
    }
    else
    {
        string check;
        if (n_a > 0)
        {
            check = last_char + "A";
            if (forbidden.find(check) == forbidden.end())
            {
                permute(N, n_a - 1, n_b, n_c, tmp + "A", "A");
            }
        }
        if (n_b > 0)
        {
            check = last_char + "B";
            if (forbidden.find(check) == forbidden.end())
            {
                permute(N, n_a, n_b - 1, n_c, tmp + "B", "B");
            }
        }
        if (n_c > 0)
        {
            check = last_char + "C";
            if (forbidden.find(check) == forbidden.end())
            {
                permute(N, n_a, n_b, n_c - 1, tmp + "C", "C");
            }
        }
    }
}

int main()
{
    int N, i, j, k;
    cin >> N >> i >> j >> k;
    int M;
    cin >> M;
    string f;
    while (M--)
    {
        cin >> f;
        forbidden.insert(f);
    }
    string tmp;
    string c;
    permute(N, i, j, k, tmp, c);
    cout << result.size() << "\n";
    for (string s : result)
    {
        cout << s << "\n";
    }
    return 0;
}