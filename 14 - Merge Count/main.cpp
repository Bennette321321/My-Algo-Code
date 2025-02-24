#include <iostream>
#include <vector>

using namespace std;

void count_time_merge(vector<int> &num, int l, int r, int &count)
{
    if (count <= 0 || l == r - 1)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    if (count > 0)
    {
        swap(num[mid - 1], num[mid]);
        count--;
    }
    count_time_merge(num, l, mid, count);
    count_time_merge(num, mid, r, count);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if (k > (n << 1) - 1 || k % 2 == 0)
    {
        cout << -1;
    }
    else
    {
        vector<int> num(n);
        for (int i = 0; i < n; i++)
        {
            num[i] = i + 1;
        }

        // For 1 calling, there are 2 additional callings
        // 1 -> 1+2 -> 1+2+4 -> 1+2+4+8 -> ...

        int count = (k - 1) / 2;

        count_time_merge(num, 0, n, count);

        for (int &x : num)
        {
            cout << x << " ";
        }
    }
}