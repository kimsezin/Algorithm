#include<iostream>


using namespace std;


int N, S, M;
int v[101];
bool dp[101][1001];
void solve()
{
	if (S + v[1] <= M)
	{
		dp[1][S + v[1]] = true;
	}
	if (S - v[1] >= 0)
	{
		dp[1][S - v[1]] = true;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (dp[i - 1][j] == true)
			{
				if (j + v[i] <= M)
				{
					dp[i][j + v[i]] = true;
				}
				if (j - v[i] >= 0)
				{
					dp[i][j - v[i]] = true;
				}
			}
		}
	}

	for (int i = M; i >= 0; i--)
	{
		if (dp[N][i] == true)
		{
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	solve();
	return 0;
}