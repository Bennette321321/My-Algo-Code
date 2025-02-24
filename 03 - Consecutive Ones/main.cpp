#include <iostream>

using namespace std;

void consecutive_1(int target_bit, int target_con_1, int max_con_1, int cur_con_1, string tmp)
{
    if (cur_con_1 > max_con_1)
    {
        max_con_1 = cur_con_1;
    }

    if (tmp.size() == target_bit)
    {
        if (max_con_1 >= target_con_1)
        {
            cout << tmp << endl;
        }
    }
    else
    {
        // There are no bit
        if (tmp.size() == 0)
        {
            // Append 0
            consecutive_1(target_bit, target_con_1, 0, 0, tmp + '0');

            // Append 1
            consecutive_1(target_bit, target_con_1, 1, 1, tmp + '1');
        }
        else
        {
            // Append 0 means destroying consecutive of 1
            consecutive_1(target_bit, target_con_1, max_con_1, 0, tmp + '0');

            // Append 1 means increasing consecutive of 1
            consecutive_1(target_bit, target_con_1, max_con_1, cur_con_1 + 1, tmp + '1');
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    consecutive_1(n, k, 0, 0, "");
}