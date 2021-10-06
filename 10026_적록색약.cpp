#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int N;
vector<string> map;
bool visited[100][100] = { false, };
int cnt = 0;
void dfs(int x, int y)
{
	char Cur = map[x][y];
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (visited[nx][ny] == false)
			{
				if (map[nx][ny] == Cur)
				{
					visited[nx][ny] = true;
					dfs(nx, ny);
				}
			}
		}
	}
}
void solution(int _N, vector<string> _map)
{
	N = _N;
	map = _map;
	vector<string> RB_map=_map;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (RB_map[i][j] == 'G')
			{
				RB_map[i][j] = 'R';
			}
			if (visited[i][j] == false)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';
	cnt = 0;
	memset(visited, false, sizeof(visited));
	map = RB_map;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;


}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		map.push_back(temp);
	}
	solution(N,map);
}