#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long N, A;
    cin >> N >> A;

    vector<long long> T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }
    long long c;
    for (int i = 0; i < A; i++)
    {
        cin >> c;
        long long l_time = 0;
        long long r_time = 1e12;
        while (l_time < r_time)
        {
            long long X = N;
            long long mid_time = l_time + (r_time - l_time) / 2;
            int j = 0;
            while (j < N)
            {
                X += mid_time / T[j];
                j++;
            }
            if (c <= X)
            {
                r_time = mid_time;
            }
            else
            {
                l_time = mid_time + 1;
            }
        }
        cout << r_time << "\n";
    }
}