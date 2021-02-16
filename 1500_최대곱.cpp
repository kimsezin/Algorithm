#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

unsigned long long int Max(int S, int K)
{
	unsigned long long int sum = 1;
	int mok = S / K;
	int na = S % K;
	for (int i = 0; i < na; i++)
	{
		sum = sum * (mok + 1);
	}
	for (int i = 0; i < K-na; i++)
	{
		sum = sum * mok;
	}
	return sum;
}
int main()
{
	int S, K;
	scanf("%d %d", &S, &K);
	unsigned long long int result;
	if (K <= 20 and K <= S <= 100)
	{
		result = Max(S, K);
		printf("%llu", result);
	}
	return 0;
}

