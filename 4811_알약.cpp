#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int N;

long long medicine[31][31] = { 0, };
int cnt = 0;
void solve(int _N)
{
	for (int h = 0; h < 31; h++)
	{
		for (int w = 0; w < 31; w++)
		{
			if (h > w)
			{
				continue;
			}
			if (h == 0)
			{
				medicine[w][h] = 1;
			}
			else
			{
				medicine[w][h] = medicine[w - 1][h] + medicine[w][h - 1];
			}
		}
	}

}
int main()
{
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
		{
			return 0;
		}
		solve(N);
		cout << medicine[N][N] << endl;
	}
	return 0;
}