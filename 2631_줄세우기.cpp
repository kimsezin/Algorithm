#include<iostream>
#include<vector>
using namespace std;
int N;
int sort[201];

int Sort()
{
	int dp[201];
	int max_value = 0;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (sort[j] < sort[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (max_value < dp[i])
		{
			max_value = dp[i];
		}
		
	}
	return N - max_value;
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> sort[i];
	}

	cout << Sort() << endl;
	return 0;
}