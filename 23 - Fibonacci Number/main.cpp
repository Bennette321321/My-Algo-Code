#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int first = 0;
    int second = 1;
    int result = first + second;
    for (int i = 2; i < N; i++) {
        first = second;
        second = result;
        result = first + second;
    }
    cout << result;
}