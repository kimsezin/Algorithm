#include<iostream>
#include<queue>
using namespace std;
int N;
int _index = 9;
queue<long long> q;
long long result[1000001];
void solve()
{
	while (_index <= N)
	{
		if (q.empty())
		{
			return;
		}
		long long number = q.front();
		q.pop();
		int lastnum = number % 10;
		for (int i = 0; i < lastnum; i++)
		{
			q.push(number * 10 + i);
			_index = _index + 1;
			result[_index] = number * 10 + i;
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 1; i < 10; i++)
	{
		q.push(i);
		result[i] = i;
	}
	solve();
	if (!result[N] && N)
	{
		cout << -1 << endl;
	}
	cout << result[N];
	return 0;
}