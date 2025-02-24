#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, int> num_student_per_date;
// student counter for each date

map<int, set<int>> student_info;
// coming dates for each students

set<int> compare_date;
// date checker

void find_min_students(int num_days, int &min_student,
                       vector<bool> &student_coming,
                       int num_student_coming,
                       int num_target_date)
{
    if (compare_date.size() == num_target_date)
    {
        min_student = min(num_student_coming, min_student);

        for (int i = 0; i < student_coming.size(); i++)
        {
            if (student_coming[i] == true)
            {
                student_coming[i] = false;
                num_student_coming--;

                for (int d : student_info[i])
                {
                    num_student_per_date[d]--;
                    if (num_student_per_date[d] == 0)
                    {
                        compare_date.erase(d);
                    }
                }

                if (num_student_coming > 0)
                {
                    find_min_students(num_days, min_student, student_coming, num_student_coming, num_target_date);
                }

                student_coming[i] = true;
                num_student_coming++;
                for (int d : student_info[i])
                {
                    num_student_per_date[d]++;
                    compare_date.insert(d);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int num_target_date = n;

    for (int i = 1; i <= n; i++)
    {
        compare_date.insert(i);
    }

    vector<bool> student_coming(m, true);
    // student checker

    int k;

    for (int i = 0; i < m; i++)
    {
        cin >> k;
        set<int> s;
        int x;
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            s.insert(x);
            num_student_per_date[x]++;
        }
        student_info[i] = s;
    }

    int min_student = m;
    // possible minimum number of students

    int num_student_coming = m;
    // number of coming students

    find_min_students(n, min_student, student_coming, num_student_coming, num_target_date);

    cout << min_student;
}
