// O(n)

#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a = 0, b = 0;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        if (i & 1)
        {
            a -= m;
            b = max(b + m, m);
        }
        else
        {
            a = max(a + m, m);
            b -= m;
        }
        res = max(res, max(a, b));
    }
    cout << res;
};
