#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int recur(int n, int a, int b, int c, map<int, int> &memo)
{
    if (n < 0)
    {
        // n < 0 mean impossible to cut (represent as -1)
        memo[n] = -1;
        return memo[n];
    }
    if (n == 0)
    {
        // n = 0 can be cut to 0 pieces
        memo[n] = 0;
        return 0;
    }
    if (memo.find(n) != memo.end())
    {
        return memo[n];
    }

    int cut_a = recur(n - a, a, b, c, memo);
    int cut_b = recur(n - b, a, b, c, memo);
    int cut_c = recur(n - c, a, b, c, memo);

    // all ways are impossible
    if (cut_a < 0 && cut_b < 0 && cut_c < 0)
    {
        memo[n] = -1;
        return memo[n];
    }

    // some ways are possible
    if (cut_a < 0 && cut_b < 0)
    {
        memo[n] = cut_c + 1;
        return memo[n];
    }
    if (cut_a < 0 && cut_c < 0)
    {
        memo[n] = cut_b + 1;
        return memo[n];
    }
    if (cut_b < 0 && cut_c < 0)
    {
        memo[n] = cut_a + 1;
        return memo[n];
    }
    if (cut_a < 0)
    {
        memo[n] = max(cut_b, cut_c) + 1;
        return memo[n];
    }
    if (cut_c < 0)
    {
        memo[n] = max(cut_b, cut_a) + 1;
        return memo[n];
    }
    if (cut_b < 0)
    {
        memo[n] = max(cut_a, cut_c) + 1;
        return memo[n];
    }

    memo[n] = max({cut_a, cut_b, cut_c}) + 1;
    return memo[n];
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    map<int, int> memo;
    int result = recur(n, a, b, c, memo);
    cout << result;
}