#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> coins(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(M + 1, M + 1);
    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        int coin = coins[i];
        for (int j = coin; j <= M; j++)
        {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[M] == M + 1)
    {
        cout << -1;
    }
    else
    {
        cout << dp[M];
    }
}
