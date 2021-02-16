#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int RGB(int N)
{
	int Color[1001][3] = { 0, };
	int price[3] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &price[0], &price[1], &price[2]);
		Color[i][0] = min(Color[i - 1][1], Color[i - 1][2]) + price[0];
		Color[i][1] = min(Color[i - 1][0], Color[i - 1][2]) + price[1];
		Color[i][2] = min(Color[i - 1][0], Color[i - 1][1]) + price[2];
	}

	return min(Color[N][0], min(Color[N][1], Color[N][2]));
}
int main()
{
	int N;

	scanf("%d", &N);

	int _result;
	if (2 <= N <= 1000)
	{
		_result = RGB(N);
	}

	printf("%d",_result);
	return 0;
}