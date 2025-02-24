#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    int max_sum = arr[0];
    int sum_cur_subarray = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        // arr[i] -> new subarray
        // sum_cur_subarray + arr[i] -> expand current subarray

        sum_cur_subarray = max(sum_cur_subarray + arr[i], arr[i]);
        max_sum = max(max_sum, sum_cur_subarray);
    }
    return max_sum;
}

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << maxSubarraySum(arr);
    return 0;
}