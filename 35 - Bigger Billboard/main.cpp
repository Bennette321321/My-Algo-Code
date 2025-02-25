#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> billboards(N);
    for (int i = 0; i < N; i++)
    {
        cin >> billboards[i];
    }

    vector<int> max_num_seen(N);

    max_num_seen[0] = billboards[0];
    max_num_seen[1] = max(max_num_seen[0], billboards[1]);
    max_num_seen[2] = max({max_num_seen[1], billboards[2]});

    for (int i = 3; i < N; i++)
    {
        max_num_seen[i] = max({max_num_seen[i - 3] + billboards[i],
                               max_num_seen[i - 2],
                               max_num_seen[i - 1]});
    }

    cout << max_num_seen[N - 1];
}