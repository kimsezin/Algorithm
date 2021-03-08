#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
queue<int> q;
int result[100001] = { 0, };
bool visited[100001] = { 0, };

void Set()
{
	for (int i = 0; i < 100001; i++)
	{
		result[i] = 9999999;
	}
}

void solve(int _K)
{
	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		if (value == _K)
		{
			cout << result[value];
			return;
		}
		if (visited[value] == false)
		{
			visited[value] = true;

			if (value * 2 <= 100000 and result[value * 2] > result[value])
			{
				q.push(value * 2);
				result[value * 2] = result[value];
			}
			if (value - 1 >= 0 and result[value - 1] > result[value] + 1)
			{
					q.push(value - 1);
					result[value - 1] = result[value] + 1;
			}
			if (value + 1 <= 100000 and result[value + 1] > result[value] + 1)
			{
					q.push(value + 1);
					result[value + 1] = result[value] + 1;
			}
		}
	}
}
int main()
{
	int N, K;
	cin >> N >> K;
	if (N == K)
	{
		cout << 0;
		return 0;
	}
	q.push(N);
	Set();
	result[N] = 0;
	solve(K);
	return 0;
}