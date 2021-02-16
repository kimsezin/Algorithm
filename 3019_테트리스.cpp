#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int C, P;
int map[100] = { 0, };

int solve()
{
	int count = 0;
	if (P == 1)
	{
		for (int i = 0; i < C; i++)
		{
			if(map[i])
		}
	}
	else if (P == 2)
	{

	}
	else if (P == 3)
	{

	}
	else if (P == 4)
	{

	}
	else if (P == 5)
	{

	}
	else if (P == 6)
	{

	}
	else if (P == 7)
	{

	}
	return count;
}
int main()
{
	scanf("%d %d", &C, &P);

	int result;
	if (1 <= C <= 100 and 1 <= P <= 7)
	{
		for (int i = 0; i < C; i++)
		{
			scanf("%d", map[i]);
		}
		result = solve();
	}

	cout << result;
	return 0;
}