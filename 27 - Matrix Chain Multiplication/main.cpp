#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int mcm(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    cout << mcm(arr, n + 1);

    return 0;
}
