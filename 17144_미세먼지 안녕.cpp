#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int R, C, T;
int map[6][50];
bool visted[6][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void init()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			map[i][j] = 999999;
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
}
void solve()
{
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
			{
				if (map[j][k] == 999999)
				{
					continue;
				}
				else if (map[j][k] == -1)
				{
					continue;
				}
				else if (j >= 0 or k >= 0)
				{
					if (map[j][k] == 0)
					{
						continue;
					}
					else
					{
						int nx = j;
						int ny = k;
						for (int z = 0; z < 4; z++)
						{
							nx = nx + dx[z];
							ny = ny + dy[z];
							if (nx >= 0 and nx < R and ny >= 0 and ny < C and visited[nx][ny]==0
							{
								map[nx][ny] = map[j][k] / 5;
								
							}
						}
						
					}
				}
			}
		}
	}
}
int main()
{
	cin >> R >> C >> T;
	init();

	solve();
	return 0;
}