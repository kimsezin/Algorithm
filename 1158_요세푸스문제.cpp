#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
using namespace std;
int N, K;
void doQueue(queue<int> q)
{
	cout << '<';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K - 1; j++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		if (i == N - 1)
		{
			cout << q.front() << '>';
			return;
		}
		cout << q.front() << ", ";
		q.pop();
		
	}
	
}
int main()
{
	
	cin >> N >> K;
	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		q.push(i+1);
	}

	doQueue(q);
	return 0;
}