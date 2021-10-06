#include <string>
#include <vector>

using namespace std;
int check[200];

void dfs(int x, int n, vector<vector<int>> computers)
{
    check[x] = 1;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0 && computers[x][i] == 1)
        {
            dfs(i, n, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}

int main()
{
    solution(3, { {1, 1, 0},{1, 1, 0},{0, 0, 1} });
}