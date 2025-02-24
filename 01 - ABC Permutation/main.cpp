#include <iostream>
#include <set>

using namespace std;

void permute(int length, int n_a, int n_b, int n_c, string tmp, set<string> &result)
{
    if (tmp.length() < length)
    {
        if (n_a > 0)
        {
            permute(length, n_a - 1, n_b, n_c, tmp + 'A', result);
        }
        if (n_b > 0)
        {
            permute(length, n_a, n_b - 1, n_c, tmp + 'B', result);
        }
        if (n_c > 0)
        {
            permute(length, n_a, n_b, n_c - 1, tmp + 'C', result);
        }
    }
    else
    {
        result.insert(tmp);
    }
}

int main()
{
    int N, i, j, k;
    cin >> N >> i >> j >> k;
    set<string> result;
    permute(N, i, j, k, "", result);
    cout << result.size() << endl;
    for (string s : result)
    {
        cout << s << endl;
    }
}