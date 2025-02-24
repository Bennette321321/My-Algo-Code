#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, long> memo;

long c(int n, int k) {
    pair<int, int> pk = make_pair(n, k);
    if (n == k) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    if (memo.find(pk) != memo.end()) {
        return memo[pk];
    }
    memo[pk] = c(n-1, k-1) + c(n-1, k);
    return memo[pk];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << c(n, k) << endl;
}