#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void reverse_vector(vector<int> &v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        swap(v[i], v[v.size() - 1 - i]);
    }
}

bool check_virus(vector<int> &v, int length)
{
    if (length == 2)
    {
        return ((v[0] == 0) && (v[1] == 1));
    }
    int half_length = length / 2;
    int a_idx = 0;
    int b_idx = half_length;
    vector<int> a(half_length);
    vector<int> b(half_length);
    for (int i = 0; i < half_length; i++)
    {
        a[i] = v[a_idx];
        b[i] = v[b_idx];
        a_idx++;
        b_idx++;
    }
    bool A = check_virus(a, a.size()) && check_virus(b, b.size());
    reverse_vector(a);
    bool B = check_virus(a, a.size()) && check_virus(b, b.size());

    return (A || B);
}

int main()
{
    int n, k;
    cin >> n >> k;

    int length = pow(2, k);

    vector<int> dna(length);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> dna[j];
        }
        if (check_virus(dna, length))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}