#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    map<int, int> mm;

    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        mm[a] = max(mm[a], b);
    }

    int start = mm.begin()->first;
    int end = mm.begin()->second;

    for (auto &it : mm)
    {
        if (end + 1 < it.first)
        {
            // Can't connect to the next part
            cout << start << " " << end << " ";
            start = it.first;
            end = it.second;
        }
        else
        {
            // Can connect to the next part
            end = max(end, it.second);
        }
    }
    cout << start << " " << end << " ";
}