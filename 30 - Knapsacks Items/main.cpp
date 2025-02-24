#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> values(n), weights(n);

    // Read values of items
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    // Read weights of items
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    vector<vector<int>> V(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cin >> V[i][j];
        }
    }

    int remaining_capacity = m;

    vector<int> selected_items;
    for (int a = n; a > 0; a--)
    {
        if (V[a][remaining_capacity] != V[a - 1][remaining_capacity])
        {
            selected_items.push_back(a);
            remaining_capacity -= weights[a - 1];
        }
    }

    cout << selected_items.size() << endl;

    for (int i = 0; i < selected_items.size(); i++)
    {
        cout << selected_items[i] << " ";
    }
    cout << endl;
}
