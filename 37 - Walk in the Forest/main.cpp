#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> points(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> points[i][j];
        }
    }
    vector<vector<int>> dp(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || j == 0)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = points[i][j];
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] + points[i][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + points[i][j];
                }
            }
            else
            {
                dp[i][j] = max({dp[i - 1][j - 1] + 2 * points[i][j],
                                dp[i][j - 1] + points[i][j],
                                dp[i - 1][j] + points[i][j]});
            }
        }
    }

    cout << dp[r - 1][c - 1];
}