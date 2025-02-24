#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int target_sum, l, r;
    bool found;
    for (int i = 0; i < M; i++)
    {
        cin >> target_sum;
        found = false;
        for (int j = 0; j <= N - 1; j++)
        {
            int cur_num = A[j];
            l = j + 1;
            r = N - 1;
            while (l < r)
            {
                if (target_sum == cur_num + A[l] + A[r])
                {
                    found = true;
                    break;
                }
                else if (target_sum > cur_num + A[l] + A[r])
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }

            if (found)
            {
                break;
            }
        }
        if (!found)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}