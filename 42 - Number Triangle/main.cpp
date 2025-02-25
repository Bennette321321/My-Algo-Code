#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> triangles(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> triangles[i][j];
        }
    }

    vector<vector<int>> max_sum_triangles(N, vector<int>(N, 0));

    int max_sum;

    // 1                    // 1
    // 2 3          =>      // 3 4      =>      9
    // 4 5 1                // 7 9 4

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 && j == 0)
            {
                max_sum_triangles[i][j] = triangles[i][j];
            }
            else if (j == 0)
            {
                max_sum_triangles[i][j] = max_sum_triangles[i - 1][j] + triangles[i][j];
            }
            else if (i == j)
            {
                max_sum_triangles[i][j] = max_sum_triangles[i - 1][j - 1] + triangles[i][j];
            }
            else
            {
                max_sum_triangles[i][j] = triangles[i][j] + max(max_sum_triangles[i - 1][j],
                                                                max_sum_triangles[i - 1][j - 1]);
            }
            if (i == N - 1)
            {
                if (j == 0)
                {
                    max_sum = max_sum_triangles[i][j];
                }
                else
                {
                    if (max_sum_triangles[i][j] > max_sum)
                    {
                        max_sum = max_sum_triangles[i][j];
                    }
                }
            }
        }
    }

    cout << max_sum;
}