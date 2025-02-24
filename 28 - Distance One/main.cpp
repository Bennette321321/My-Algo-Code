#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int v[n + 1];
    for (int i = 1; i <= k; i++)
    {
        v[i] = i + 1;
    }
    for (int i = k + 1; i <= n; i++)
    {
        v[i] = (v[i - 1] + v[i - k]) % 100000007;
    }
    cout << v[n];
}
