#include <iostream>
#include <vector>

using namespace std;

void map_count(vector<vector<int>> &map, int cur_row, int cur_col,
               int target_row, int target_col, string tmp)
{
    // 1 = Can't Go Here (It's the wall or You have passed here before)
    // 0 = Can Go Here

    if (cur_row == target_row && cur_col == target_col)
    {
        cout << tmp << endl;
    }
    else
    {
        map[cur_row][cur_col] = 1;

        // Right (A) -> Down (B) -> Up (C)
        // Make Alphabetical Order so no need to store the path in set
        if (cur_col + 1 < map[0].size() && map[cur_row][cur_col + 1] == 0)
        {
            // Try Go Right
            map_count(map, cur_row, cur_col + 1, target_row, target_col, tmp + 'A');
        }
        if (cur_row + 1 < map.size() && map[cur_row + 1][cur_col] == 0)
        {
            // Try Go Down
            map_count(map, cur_row + 1, cur_col, target_row, target_col, tmp + 'B');
        }
        if (cur_row - 1 >= 0 && map[cur_row - 1][cur_col] == 0)
        {
            // Try Go Up
            map_count(map, cur_row - 1, cur_col, target_row, target_col, tmp + 'C');
        }

        map[cur_row][cur_col] = 0;
    }
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> map(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }
    map_count(map, 0, 0, R - 1, C - 1, "");
    cout << "DONE" << endl;
}