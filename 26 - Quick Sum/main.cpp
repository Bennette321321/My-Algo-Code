#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> A(n, vector<int>(m, 0));
  vector<vector<int>> p(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> A[i][j];
    }
  }
  p[0][0] = A[0][0];
  for (int j = 1; j < m; j++)
  {
    p[0][j] = p[0][j - 1] + A[0][j];
  }
  for (int i = 1; i < n; i++)
  {
    p[i][0] = p[i - 1][0] + A[i][0];
    for (int j = 1; j < m; j++)
    {
      p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + A[i][j];
    }
  }

  for (int i = 0; i < k; i++)
  {
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int a, b, c, d;
    a = p[r2][c2];
    b = (r1 == 0 ? 0 : p[r1 - 1][c2]);
    c = (c1 == 0 ? 0 : p[r2][c1 - 1]);
    d = (r1 == 0 || c1 == 0 ? 0 : p[r1 - 1][c1 - 1]);

    cout << a - b - c + d << endl;
  }
}
