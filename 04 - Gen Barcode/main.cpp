#include <iostream>

using namespace std;

void gen_barcode(int target_num_all, int target_num_1, int cur_num_1, string tmp)
{
    if (tmp.size() == target_num_all && target_num_1 == cur_num_1)
    {
        cout << tmp << endl;
    }
    // If there is a place to add next number
    else if (tmp.size() < target_num_all)
    {
        // Try Append 0
        gen_barcode(target_num_all, target_num_1, cur_num_1, tmp + '0');

        // Try Append 1
        gen_barcode(target_num_all, target_num_1, cur_num_1 + 1, tmp + '1');
    }
}

int main()
{
    int A, B;
    cin >> A >> B;
    gen_barcode(B, A, 0, "");
}