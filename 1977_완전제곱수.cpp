#include<iostream>

using namespace std;
int M, N;

void solve()
{
	int mul;
	int min = 99999;
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		mul = i * i;
		if (M <= mul and mul <= N)
		{
			if (min > mul)
			{
				min = mul;
			}
			sum = sum + mul;
		}
	}

	if (min == 99999)
	{
		cout << -1;
	}
	else
	cout << sum << endl << min;
	
}

int main()
{
	cin >> M >> N;
	if (M == 1 and N == 1)
	{
		cout << -1;
		return 0;
	}
	solve();

	return 0;
}