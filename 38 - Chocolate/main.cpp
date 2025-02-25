#include <iostream>
#include <vector>
#include <map>

using namespace std;

int count_ways_to_eat(int n, vector<int> S, int k, map<int, int> &memo)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (memo.find(n) != memo.end())
    {
        return memo[n];
    }
    for (int i = 0; i < k; i++)
    {
        memo[n] = (memo[n] + count_ways_to_eat(n - S[i], S, k, memo) % 1000003) % 1000003;
    }
    return memo[n];
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> S(k);
    for (int i = 0; i < k; i++)
    {
        cin >> S[i];
    }

    map<int, int> memo;

    int result = count_ways_to_eat(n, S, k, memo);

    cout << result;
}