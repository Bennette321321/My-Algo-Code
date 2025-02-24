#include <iostream>

using namespace std;

int mod(int X, int N, int K)
{
    if (N == 0)
    {
        return 1;
    }
    if (N == 1)
    {
        return X % K;
    }
    if (N % 2 == 0)
    {
        return (mod(X, N / 2, K) * mod(X, N / 2, K)) % K;
    }
    else
    {
        return (mod(X, 1, K) * mod(X, N - 1, K)) % K;
    }
}

int main()
{
    int X, N, K;
    cin >> X >> N >> K;
    cout << mod(X, N, K);
}