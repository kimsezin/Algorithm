#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	bool visited[100001] = { 0, };

	if (0 <= N <= 100000 or 0 <= K <= 100000)
	{
		queue<pair<int, int>> q;

		q.push({ N, 0 });
		visited[N] = 1;
		
		while (!q.empty())
		{
			int value = q.front().first;
			int cnt = q.front().second;
			q.pop();

			if (value == K)
			{
				printf("%d", cnt);
				return 0;
			}
			if (value + 1 <= 100000 and !visited[value + 1])
			{
				q.push({ value + 1, cnt + 1 });
				visited[value + 1] = 1;
			}
			if (value - 1 >= 0 and !visited[value - 1])
			{
				q.push({ value - 1, cnt + 1 });
				visited[value - 1] = 1;
			}
			if (value * 2 <= 100000 and !visited[value * 2])
			{
				q.push({ value * 2, cnt + 1 });
				visited[value * 2] = 1;
			}
		}
	}
	return 0;
}