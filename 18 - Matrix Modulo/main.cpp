#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> v1, vector<int> v2, int k)
{
    return {(v1[0] * v2[0] + v1[1] * v2[2]) % k, (v1[0] * v2[1] + v1[1] * v2[3]) % k,
            (v1[2] * v2[0] + v1[3] * v2[2]) % k, (v1[2] * v2[1] + v1[3] * v2[3]) % k};
}

vector<int> mod(vector<int> v, int n, int k)
{
    if (n == 0)
    {
        return {1, 0, 0, 1};
    }
    else
    {
        if (n % 2 == 0)
        {
            vector<int> vv = mod(v, n / 2, k);
            return mul(vv, vv, k);
        }
        else
        {
            return mul(mod(v, n - 1, k), v, k);
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(4);
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    vector<int> result = mod(v, n, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << result[i] << " ";
    }
}
