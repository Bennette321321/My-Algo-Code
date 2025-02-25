#include <iostream>

using namespace std;

long long count = 0;

void recur(long long n, string first_string, string second_string, string first_last_char, string second_last_char)
{
    if (first_string.length() == n && second_string.length() == n)
    {
        count++;
        count %= 100000007;
        return;
    }
    if (first_string.length() < n)
    {
        // add 0 -> no restriction
        recur(n, first_string + "0", second_string, "0", second_last_char);

        // add 1 -> no_restriction
        if (first_last_char != "1")
        {
            recur(n, first_string + "1", second_string, "1", second_last_char);
        }
    }
    else if (second_string.length() < n)
    {
        // add 0 -> no restriction
        recur(n, first_string, second_string + "0", first_last_char, "0");

        // add 1 -> second_last_char must not be 1
        // and in this position in the first_string must not be 1
        if (second_last_char != "1" && first_string[second_string.length()] != '1')
        {
            recur(n, first_string, second_string + "1", first_last_char, "1");
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    recur(n, "", "", "", "");
    cout << count;
}