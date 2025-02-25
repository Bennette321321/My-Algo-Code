#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<long long> memo(N + 1);
    memo[0] = 1;
    memo[1] = 2;
    memo[2] = 4;

    // From direct approach, we can find the relation that F(n) = F(n-3) - F(n-2) + 2F(n-1)
    for (long long i = 3; i <= N; i++)
    {
        memo[i] = (memo[i - 3] - memo[i - 2] + 2 * memo[i - 1] + 100000007) % 100000007;
    }

    cout << memo[N];
}