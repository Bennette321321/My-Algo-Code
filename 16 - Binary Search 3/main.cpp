#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int> &v, int find_num, int left_idx, int right_idx)
{
    if (left_idx > right_idx)
    {
        if (left_idx < 0)
        {
            return -1;
        }
        if (left_idx > v.size())
        {
            return v.size() - 1;
        }
        return left_idx - 1;
    }
    int mid_idx = left_idx + (right_idx - left_idx) / 2;
    if (v[mid_idx] == find_num)
    {
        while (mid_idx + 1 < v.size() && v[mid_idx] == v[mid_idx + 1])
        {
            mid_idx++;
        }
        return mid_idx;
    }
    else if (v[mid_idx] < find_num)
    {
        return bs(v, find_num, mid_idx + 1, right_idx);
    }
    else
    {
        return bs(v, find_num, left_idx, mid_idx - 1);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int find_num;
    for (int i = 0; i < M; i++)
    {
        cin >> find_num;
        cout << bs(v, find_num, 0, N) << "\n";
    }
}