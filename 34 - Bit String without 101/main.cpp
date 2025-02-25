#include <iostream>

using namespace std;

long long count = 0;

void permute(long long N, string tmp, string last_tmp, string second_last_tmp)
{
    if (tmp.length() == N)
    {
        count++;
        count %= 100000007;
        return;
    }
    if (tmp.length() < N)
    {
        // add 0
        permute(N, tmp + "0", "0", last_tmp);

        // add 1
        if (second_last_tmp + last_tmp != "10")
        {
            permute(N, tmp + "1", "1", last_tmp);
        }
        else
        {
            return;
        }
    }
}

int main()
{
    long long N;
    cin >> N;
    permute(N, "", "", "");
    cout << count;
}