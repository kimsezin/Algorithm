#include<iostream>
#include<queue>
#include<string>

using namespace std;
queue<int> q;
void DoQueue(string input, int num)
{
	if (input == "push")
	{
		q.push(num);
	}
	else if (input == "pop")
	{
		if (q.empty())
		{
			cout << -1 << endl;
			return;
		}
		else
		{
			cout << q.front() << endl;
			q.pop();
		}
	}
	else if (input == "size")
	{
		cout << q.size() << endl;
	}
	else if (input == "empty")
	{
		if (q.empty())
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else if (input == "front")
	{
		if (q.empty())
		{
			cout << -1 << endl;
			return;
		}
		else
		cout << q.front() << endl;
	}
	else if (input == "back")
	{
		if (q.empty())
		{
			cout << -1 << endl;
			return;
		}
		else
		cout << q.back() << endl;
	}
}
int main()
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		string input;
		cin >> input;
		int num = 0;
		if (input == "push")
		{
			cin >> num;
		}
		DoQueue(input, num);
	}
	return 0;
}