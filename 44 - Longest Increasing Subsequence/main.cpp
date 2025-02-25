#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(vector<int> &arr)
{
    vector<int> sub;

    for (int num : arr)
    {
        auto it = lower_bound(sub.begin(), sub.end(), num); // Find position in sub
        if (it == sub.end())
        {
            sub.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

    return sub.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr) << endl;
}
