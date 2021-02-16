#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

unsigned long long N, M;
unsigned long long _time[100000];
unsigned long long result_time[100000];

int main()
{
	unsigned long long temp;
	scanf("%lld %lld", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &temp);
		_time[i] = temp;
		result_time[i] = temp;
	}
	int min_index;
	unsigned long long min_value;
	for (int i = 0; i < M; i++)
	{
		min_index = 0;
		min_value = 99999999;
		for (int j = 0; j < N; j++)
		{
			if (result_time[j] < min_value)
			{
				min_value = result_time[j];
				min_index = j;
			}
		}
		result_time[min_index] = result_time[min_index] + _time[min_index];
	}
	cout << result_time[min_index] - _time[min_index];
	

	return 0;
}