#include <iostream>
#include <map>

using namespace std;

int divide = 100000007;

map<int, int> memo;

int main()
{
    int n;
    cin >> n;
    memo[1] = 3;
    memo[2] = 7;
    memo[3] = 15;

    // Direct Approach and Find the relation:
    // F(n) = 2 * F(n-1) + F(n-3)

    for (int i = 4; i <= n; i++)
    {
        memo[i] = ((2 * memo[i - 1] % divide) % divide + (memo[i - 3] % divide)) % divide;
    }
    cout << memo[n];
}