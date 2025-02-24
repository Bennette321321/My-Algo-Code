// O(n^2)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<int> S(N + 1);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            sum += A[i];
        }
        else
        {
            sum -= A[i];
        }
        S[i + 1] = sum;
    }

    int max_sum = A[0];
    for (int p = 1; p <= N; p++)
    {
        for (int q = p; q <= N; q++)
        {
            sum = S[q] - S[p - 1];
            if (p % 2 == 0)
            {
                sum *= -1;
            }
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
    cout << max_sum << "\n";
}