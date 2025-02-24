#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> scores(n);

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    vector<int> memo(n, 0);

    memo[0] = scores[0];
    if (n > 1)
    {
        memo[1] = scores[0] + scores[1];
    }
    if (n > 2)
    {
        memo[2] = max({scores[0] + scores[1] + scores[2],
                       scores[0] + scores[2]});
    }

    for (int i = 3; i < n; i++)
    {
        memo[i] = max({memo[i - 1], memo[i - 2], memo[i - 3]}) + scores[i];
    }

    cout << memo[n - 1] << endl;
}
