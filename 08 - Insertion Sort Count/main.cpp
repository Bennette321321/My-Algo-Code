#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++)
    {
        int target_number;
        cin >> target_number;

        for (int j = 0; j < n; j++)
        {
            // Find the target number's position
            if (A[j] == target_number)
            {
                int ans = 0;
                for (int k = 0; k < j; k++)
                {
                    // Count the time to replace before replace the target number
                    if (A[k] > target_number)
                    {
                        ans++;
                    }
                }
                cout << ans << '\n';
                break;
            }
        }
    }
}