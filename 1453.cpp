#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	if (N < 0 or N > 100)
	{
		return 0;
	}

	int seat[101] = { 0, };
	int person;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &person);

		if (seat[person] == 0)
		{
			seat[person] = 1;
		}
		else
		{
			count++;
		}

	}
	printf("%d", count);
	return 0;
}