#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> &billboards, int end_idx, vector<int> &max_num_seen)
{
    if (end_idx < 0)
    {
        return 0;
    }

    if (max_num_seen[end_idx] != -1)
    {
        return max_num_seen[end_idx];
    }

    int dont_take = findMax(billboards, end_idx - 1, max_num_seen);

    int take = billboards[end_idx] + findMax(billboards, end_idx - 2, max_num_seen);

    max_num_seen[end_idx] = max(dont_take, take);

    return max_num_seen[end_idx];
}

int main()
{
    int n;
    cin >> n;
    vector<int> billboards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> billboards[i];
    }

    vector<int> max_num_seen(n, -1);

    cout << findMax(billboards, n - 1, max_num_seen);
}
