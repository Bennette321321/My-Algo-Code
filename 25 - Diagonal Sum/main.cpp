#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;

int main() {
    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            cin >> num;
            v.push_back(num);
        }
        matrix.push_back(v);
    }

    int max = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                int r = i + k;
                int c = j + k;
                if (r >= n || c >= n) {
                    break;
                }
                sum += matrix[r][c];
                if (sum > max) {
                    max = sum;
                }
            }
        }
    }
    cout << max;
}