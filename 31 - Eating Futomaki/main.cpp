#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxFutomaki(int start_idx, int end_idx, vector<int> &futomaki, vector<vector<bool>> &memo, vector<vector<int>> &result)
{
    if (start_idx >= end_idx)
    {
        // ถ้า futomaki เหลืออยู่ 0 ชิ้น
        return 0;
    }
    if (memo[start_idx][end_idx])
    {
        // ถ้าเคยคิดช่วง futomaki นี้แล้ว คืนค่าที่เคยเก็บไว้
        return result[start_idx][end_idx];
    }

    int cut_1_left_1_right = max(futomaki[start_idx], futomaki[end_idx]) + getMaxFutomaki(start_idx + 1, end_idx - 1, futomaki, memo, result);
    int cut_2_left = max(futomaki[start_idx], futomaki[start_idx + 1]) + getMaxFutomaki(start_idx + 2, end_idx, futomaki, memo, result);
    int cut_2_right = max(futomaki[end_idx], futomaki[end_idx - 1]) + getMaxFutomaki(start_idx, end_idx - 2, futomaki, memo, result);

    int max_delicious = max({cut_1_left_1_right, cut_2_left, cut_2_right});

    memo[start_idx][end_idx] = true;
    result[start_idx][end_idx] = max_delicious;

    return max_delicious;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<bool>> memo(n + 1, vector<bool>(n + 1, false));
    vector<vector<int>> result(n + 1, vector<int>(n + 1, 0));
    vector<int> futomaki(n);

    for (int i = 0; i < n; i++)
    {
        cin >> futomaki[i];
    }

    cout << getMaxFutomaki(0, n - 1, futomaki, memo, result) << endl;
    return 0;
}
