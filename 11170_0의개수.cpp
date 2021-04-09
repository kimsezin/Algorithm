#include<iostream>

using namespace std;

int T;
int cnt = 0;
void solve()
{
	int N, M;
	cin >> N >> M;
	for (int i = N; i <= M; i++)
	{
		int num = i;
		if (num == 0)
		{
			cnt++;
		}

		while (num != 0)
		{
			if (num % 10 == 0)
			{
				cnt++;
			}
			num = num / 10;
		}
	}
}
int main()
{
	cin >> T;
	int result[20];
	for (int i = 0; i < T; i++)
	{
		solve();
		result[i] = cnt;
		cnt = 0;
	}
	for (int i = 0; i < T; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}