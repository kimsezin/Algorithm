#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;
int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int N;
	scanf("%d", &N);

	int x;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		if (x == 0)
		{
			if (pq.empty())
			{
				printf("%d\n", 0);
			}
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}
	return 0;
}