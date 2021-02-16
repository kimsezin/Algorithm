#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int N;
int map[25][25];
bool visited[25][25] = { 0, };

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int cnt = 0;
int total_cnt = 0;
priority_queue<int, vector<int>, greater<int>> pq;

void search(int x, int y)
{
	cnt=cnt+1;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] < 0 or x + dx[i] >= N or y + dy[i] < 0 or y + dy[i] >= N)
		{
			continue;
		}
		if (map[x + dx[i]][y + dy[i]] == 1 and visited[x + dx[i]][y + dy[i]] == 0)
		{
			search(x + dx[i], y + dy[i]);
		}
	}
}
void solve()
{		
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 and visited[i][j] == 0)
			{
				cnt = 0;
				total_cnt = total_cnt + 1;
				search(i,j);
				pq.push(cnt);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	if (5 <= N <= 25)
	{
		for (int i = 0; i < N; i++)
		{
			string input;
			cin >> input;
			for (int j = 0; j < N; j++)
			{
				map[i][j] = input[j] - '0';
			}
		}
		solve();
	}
	cout << total_cnt << endl;
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}
