#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int R, C;
char map[20][20];
int visited[26];
int res = 0;

void dfs(int _R, int _C, int cnt)
{
	res = max(res, cnt);
	
	for (int i = 0; i < 4; i++)
	{
		int nx = _R + dx[i];
		int ny = _C + dy[i];

		if (ny < 0 || nx < 0 || nx >= R || ny >= C)
		{
			continue;
		}

		char k = map[nx][ny]-65;
		if (visited[k]==1)
		{
			continue;
		}
		visited[k]++;
		dfs(nx, ny, cnt + 1);
		visited[k]--;
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
	visited[map[0][0] - 65] = 1;
	dfs(0, 0, 1);

	cout << res;
	return 0;
}