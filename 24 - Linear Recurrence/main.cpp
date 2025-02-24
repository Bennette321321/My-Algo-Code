#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> Cs;
vector<int> As;
map<pair<int, int>, long> memo;

long linear_recurrence(int n, int k) {
    if (n < k) {
        return As[n];
    }
    pair<int, int> pk = make_pair(n, k);
    if (memo.find(pk) != memo.end()) {
        return memo[pk] % 32717;
    }
    for (int i = 1; i <= k; i++) {
        memo[pk] += (Cs[i] * linear_recurrence(n - i, k)) % 32717;
    }
    return memo[pk] % 32717;
}

int main() {
    int k, n;
    cin >> k >> n;

    int c, a;
    Cs.push_back(-1);
    for (int i = 0; i < k; i++) {
        cin >> c;
        Cs.push_back(c);
    }
    for (int i = 0; i < k; i++) {
        cin >> a;
        As.push_back(a);
    }
    cout << linear_recurrence(n, k);
}