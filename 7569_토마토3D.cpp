#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

#define MAX 100
int M, N, H;
int box[MAX][MAX][MAX];

queue<pair<int, pair<int, int>>> q;
struct _index
{
	int z, x, y;
};
_index Dir[6] = { {0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} };
int cnt = 0;

bool full()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (box[i][j][k] == 0 and q.size() == 0)
				{
					return false;
				}

			}
		}
	}
	return true;
}
void doBfs()
{
	while (!q.empty())
	{
		int qs = q.size();
		for (int z = 0; z < qs; z++)
		{
			int _dx = q.front().second.first;
			int _dy = q.front().second.second;
			int _dz = q.front().first;
			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int nx = _dx + Dir[i].x;
				int ny = _dy + Dir[i].y;
				int nz = _dz + Dir[i].z;

				if (nx >= 0 and ny >= 0 and nz >= 0 and nx < M and ny < N and nz < H)
				{
					if (box[nz][nx][ny] == 0)
					{
						box[nz][nx][ny] = 1;
						q.push({ nz, { nx,ny } });
					}
				}
			}
			if (q.size() == 0 && full() == true)
			{
				cout << cnt << endl;
				return;
			}
			else if (q.size() == 0 && full() == false)
			{
				cout << -1 << endl;
				return;
			}
		}
		cnt++;
	}
}
int main()
{
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf("%d", &box[i][j][k]);
				if (box[i][j][k] == 1)
				{
					q.push({ i,{j,k} });
				}
			}
		}
	}
	doBfs();


}