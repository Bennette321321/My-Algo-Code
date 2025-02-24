#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    int num;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int time_inversion = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                time_inversion++;
            }
        }
    }
    cout << time_inversion++;
}