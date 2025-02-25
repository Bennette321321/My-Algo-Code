#include <iostream>

using namespace std;

int divider = 100000007;

int main()
{
    long long n;
    cin >> n;

    long long p1 = 3;
    long long p2 = 7;
    long long p3 = 2 * p2 + p1;

    if (n < 3)
    {
        if (n == 1)
        {
            cout << 3;
        }
        else
        {
            cout << 7;
        }
    }
    else
    {
        // From Direct Approach, we find that F(n) = 2 * F(n-1) + F(n-2)
        // defined as p3 = 2 * p2 + p1

        for (int i = 3; i < n; i++)
        {
            p1 = p2;
            p2 = p3;
            p3 = (2 * p2 % divider + p1 % divider) % divider;
        }
        cout << p3;
    }
}