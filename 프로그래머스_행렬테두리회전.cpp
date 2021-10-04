#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> map(rows,vector<int>(columns));
    int cnt = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            map[i][j] = cnt;
            cnt++;
        }
    }
    for (int k = 0; k < queries.size(); k++)
    {
        vector<vector<int>> copy_map = map;
        int x1 = queries[k][0] - 1;
        int y1 = queries[k][1] - 1;
        int x2 = queries[k][2] - 1;
        int y2 = queries[k][3] - 1;
        int min_value = rows * columns;

        for (int i = 1; i <= y2 - y1; i++)
        {
            map[x1][y1 + i] = copy_map[x1][y1 + i-1];
            if (min_value > map[x1][y1 + i])
            {
                min_value = map[x1][y1 + i];
            }
            map[x2][y2 - i] = copy_map[x2][y2 - i+1];
            if (min_value > map[x2][y2 - i])
            {
                min_value = map[x2][y2 - i];
            }
        }
        for (int i = 0; i < x2 - x1; i++)
        {
            map[x1 + i][y1] = copy_map[x1 + i+1][y1];
            if (min_value > map[x1 + i][y1])
            {
                min_value = map[x1 + i][y1];
            }
            map[x2 - i][y2] = copy_map[x2 - i-1][y2];
            if (min_value > map[x2 - i][y2])
            {
                min_value = map[x2 - i][y2];
            }
        }

        answer.push_back(min_value);
    }
    return answer;
}

int main()
{
    solution(100, 97, { {1,1,100,97 }
});
}