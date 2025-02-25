#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cin >> dp[i][j];
        }
    }

    string result = "";

    int j = m;

    for (int i = n; i > 0; i--)
    {
        if (dp[i - 1][j - 1] + 1 == dp[i][j])
        {
            result = s1[i - 1] + result;
            j--;
        }
    }

    cout << result;
}