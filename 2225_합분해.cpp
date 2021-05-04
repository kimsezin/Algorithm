#include<iostream>


using namespace std;

long long dp[201][201] = { 0, };
int N, K;
void init()
{
	for (int i = 0; i <= N; i++)
	{
		dp[0][i] = 0;
		dp[1][i] = 1;
	}
}

void solve()
{
	for (int k = 2; k <= K; k++)
	{
		for (int n = 0; n <= N; n++)
		{
			for (int res = 0; res <= n; res++)
			{
				dp[k][n] += dp[k - 1][n - res];
				dp[k][n] %= 1000000000;
			}
		}
	}
}
int main()
{
	cin >> N >> K;
	init();
	solve();
	cout << dp[K][N];
	return 0;
}