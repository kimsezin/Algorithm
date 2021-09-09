#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;

int main()
{
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			if (pq.empty())
			{
				cout << 0 << endl;
			}
			else
			cout << pq.top() << endl;
			pq.pop();
		}
		else
		{
			pq.push(input);
		}
	}
}