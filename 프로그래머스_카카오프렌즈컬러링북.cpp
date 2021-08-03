#include <vector>
#include <queue>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool visited[100][100];
int bfs(int i, int j, int m, int n, vector<vector<int>> map)
{
    int color = map[i][j];
    int size = 1;
    queue<pair<int, int>> Q;
    Q.push({ i,j });
    visited[i][j] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n)
            {
                if (map[nx][ny] == color && visited[nx][ny] != true)
                {
                    size++;
                    visited[nx][ny] = true;
                    Q.push({ nx,ny });
                }
            }
        }
    }
    return size;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (picture[i][j] != 0 && visited[i][j] != true)
            {
                int size = bfs(i, j, m, n, picture);
                if (size > max_size_of_one_area)
                {
                    max_size_of_one_area = size;
                }
                number_of_area++;
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}