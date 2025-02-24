#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> monster_position(m);
    for (int i = 0; i < m; i++)
    {
        cin >> monster_position[i];
    }

    vector<int> monster_power(m);
    for (int i = 0; i < m; i++)
    {
        cin >> monster_power[i];
    }

    set<int> tower_position;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        tower_position.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        int mon_pos = monster_position[i];

        // Find the tower to shoot this monster
        for (int j = max(mon_pos - w, 1); j <= min(mon_pos + w, n); j++)
        {
            if (tower_position.find(j) == tower_position.end())
            {
                // There are no towers that are in this position
                continue;
            }

            // Find the tower to shoot (Don't care of the tower's number)
            // -> remove this tower's position and decrease this monster's power by 1
            tower_position.erase(j);
            monster_power[i]--;

            // If this monster's power is 0...
            // stop finding tower to shoot and go to the next monster
            if (monster_power[i] == 0)
            {
                break;
            }
        }
    }

    int sum_power = 0;
    for (int i = 0; i < m; i++)
    {
        sum_power += monster_power[i];
    }

    cout << sum_power << endl;

    return 0;
}
