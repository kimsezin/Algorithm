#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int Tri(int N)
{
	int result = 0;
	int Triangle[501][501] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &Triangle[i][j]);
			Triangle[i][j] = Triangle[i][j] + max(Triangle[i - 1][j - 1], Triangle[i - 1][j]);
		}
	}
	int max = 0;
	for (int i = 0; i <= N; i++)
	{
		if (Triangle[N][i] > max)
		{
			max = Triangle[N][i];
		}
	}

	return max;
}
int main()
{
	int N;
	scanf("%d", &N);
	int result;
	if (1 <= N <= 500)
	{
		result = Tri(N);
	}
	printf("%d", result);

	return 0;
}

