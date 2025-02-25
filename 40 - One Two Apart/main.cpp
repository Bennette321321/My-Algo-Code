#include <iostream>

using namespace std;

int count = 0;
int divide = 100000007;

void recur(int n, string tmp, string last_char, string second_last_char)
{
    if (tmp.length() == n)
    {
        count = (count % divide + (1 % divide)) % divide;
        return;
    }
    if (tmp.length() < n)
    {
        // add 0 -> no restriction
        recur(n, tmp + "0", "0", last_char);

        // add 1 -> last_char and second_last_char must not be 2
        if (last_char != "2" && second_last_char != "2")
        {
            recur(n, tmp + "1", "1", last_char);
        }

        // add 2 -> last_char and second_last_char must not be 1
        if (last_char != "1" && second_last_char != "1")
        {
            recur(n, tmp + "2", "2", last_char);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    recur(n, "", "", "");
    cout << count;
}