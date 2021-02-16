#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


using namespace std;
int dp[10000];
int coin[100];
int N, K;

void doDP()
{
	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = coin[i]; j <= K; j++)
		{
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> coin[i];
	}

	doDP();
	cout << dp[K];
}