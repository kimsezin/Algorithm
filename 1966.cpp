#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		int number, seat, cnt = 0;
		cin >> number >> seat;
		for (int j = 0; j < number; j++)
		{
			int value;
			cin >> value;
			q.push({ j,value });
			pq.push(value);
		}

		while (q.empty() == 0)
		{
			int _index = q.front().first;
			int _value = q.front().second;
			q.pop();

			if (_value == pq.top())
			{
				pq.pop();
				cnt++;
				if (_index == seat)
				{
					cout << cnt;
					break;
				}
			}
			else
			{
				q.push({ _index, _value });
			}
		}
	}
	return 0;
}