#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>


using namespace std;

#define MAX 1000
int M, N;
int box[MAX][MAX] = { 0 };

queue <pair<int,int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void DoBfs()
{
	while (!q.empty())
	{
		int nowdx = q.front().first;
		int nowdy = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			if (0 <= nowdx + dx[i] and nowdx + dx[i] < M and
				0 <= nowdy + dy[i] and nowdy + dy[i] < N)
			{
				if (box[nowdx + dx[i]][nowdy + dy[i]] == 0)
				{
					box[nowdx + dx[i]][nowdy + dy[i]] = box[nowdx][nowdy] + 1;
					q.push({ nowdx + dx[i],nowdy + dy[i] });
				}
			}
		}
		
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}

	DoBfs();

	int max_value = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (box[i][j] > max_value)
			{
				max_value = box[i][j];
			}
		}
	}
	cout << max_value - 1;
	return 0;
}