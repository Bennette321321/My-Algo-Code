#include <iostream>
#include <vector>

using namespace std;

bool isZeroMatrix(vector<vector<int>> &A, int start_row, int start_col, int size)
{
    for (int i = start_row; i < start_row + size; i++)
    {
        for (int j = start_col; j < start_col + size; j++)
        {
            if (A[i][j] != 0)
                return false;
        }
    }
    return true;
}

int triforce(vector<vector<int>> &A, int n, int start_row, int start_col)
{
    if (n == 2)
    {
        int a = A[start_row][start_col];
        int b = A[start_row][start_col + 1];
        int c = A[start_row + 1][start_col];
        int d = A[start_row + 1][start_col + 1];

        if (d != 0 || a == 0 || b == 0 || c == 0)
        {
            return 0;
        }
        if (a == b || a == c)
        {
            return a;
        }
        if (b == c)
        {
            return b;
        }
        return 0;
    }

    int half = n / 2;
    int P = triforce(A, half, start_row, start_col);
    int Q = triforce(A, half, start_row, start_col + half);
    int R = triforce(A, half, start_row + half, start_col);
    int S = isZeroMatrix(A, start_row + half, start_col + half, half) ? 0 : -1;

    if (S != 0 || P == 0 || Q == 0 || R == 0)
    {
        return 0;
    }

    if (P == Q || P == R)
    {
        return P;
    }
    if (Q == R)
    {
        return Q;
    }
    return 0;
}

int main()
{
    int n;
    for (int _ = 0; _ < 3; _++)
    {
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        cout << triforce(v, n, 0, 0) << "\n";
    }
}