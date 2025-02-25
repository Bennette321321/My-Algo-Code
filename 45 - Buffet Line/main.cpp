#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K, m;
    cin >> n >> K >> m;

    int d[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        d[i] += d[i - 1] - m;
    }

    int p, w;
    for (int i = 0; i < K; i++)
    {
        cin >> p >> w;
        cout << lower_bound(d + 1, d + n + 1, d[p - 1] + w) - d << endl;
    }
}