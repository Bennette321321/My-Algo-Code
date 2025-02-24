// Better Version of main.cpp

#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int left_arr_idx = left;
    int right_arr_idx = mid + 1;
    int merge_arr_idx = left;

    int count = 0;

    while (left_arr_idx <= mid && right_arr_idx <= right)
    {
        if (arr[left_arr_idx] <= arr[right_arr_idx])
        {
            temp[merge_arr_idx++] = arr[left_arr_idx++];
        }
        else
        {
            temp[merge_arr_idx++] = arr[right_arr_idx++];
            count += (mid - left_arr_idx + 1);
        }
    }

    while (left_arr_idx <= mid)
    {
        temp[merge_arr_idx++] = arr[left_arr_idx++];
    }

    while (right_arr_idx <= right)
    {
        temp[merge_arr_idx++] = arr[right_arr_idx++];
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}

int mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        count += mergeSortAndCount(arr, temp, left, mid);
        count += mergeSortAndCount(arr, temp, mid + 1, right);
        count += mergeAndCount(arr, temp, left, mid, right);
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = mergeSortAndCount(arr, temp, 0, n - 1);
    cout << count;

    return 0;
}
