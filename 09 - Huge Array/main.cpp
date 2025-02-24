#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    set<pair<int, int>> s;
    // <num, amount_of_num>

    int x, c;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> c;
        s.insert(make_pair(x, c));
    }

    vector<pair<int, int>> first_index_each_number(N + 1);
    // <first_index, num>

    int i = 0;
    for (pair<int, int> p : s)
    {
        i++;
        first_index_each_number[i] = make_pair(first_index_each_number[i - 1].first + p.second, p.first);
    }

    int a;
    for (int i = 0; i < Q; i++)
    {
        cin >> a;
        pair<int, int> searcher = make_pair(a, 0);
        auto ans = lower_bound(first_index_each_number.begin(), first_index_each_number.end(), searcher);
        cout << ans->second << '\n';
    }
}