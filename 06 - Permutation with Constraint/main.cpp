#include <iostream>
#include <vector>

using namespace std;

void permute(int n, vector<int> &tmp, vector<bool> &used, vector<int> &num_edges, vector<vector<int>> &graph)
{
    // Meet the requirement
    if (tmp.size() == n)
    {
        for (int num : tmp)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // Check if the number can be used
        // (i's number of edges is 0 and i's not used yet)
        if (!used[i] && num_edges[i] == 0)
        {
            used[i] = true;
            tmp.push_back(i);
            for (int neighbor : graph[i])
            {
                num_edges[neighbor]--;
            }

            permute(n, tmp, used, num_edges, graph);

            for (int neighbor : graph[i])
            {
                num_edges[neighbor]++;
            }
            used[i] = false;
            tmp.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> num_edges(n, 0);

    int num1, num2;
    for (int i = 0; i < m; i++)
    {
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        num_edges[num2]++;
    }

    vector<bool> used(n, false);
    vector<int> tmp;

    permute(n, tmp, used, num_edges, graph);

    return 0;
}
