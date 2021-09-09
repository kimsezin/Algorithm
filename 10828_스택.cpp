#include<iostream>
#include<stack>
#include<string>

using namespace std;
stack<int> s;
void Dostack(string op, int num)
{
	if (op == "push")
	{
		s.push(num);
	}
	else if (op == "pop")
	{
		if (s.size() == 0)
		{
			cout << -1 << endl;
			return;
		}
		else
			cout << s.top() << endl;
		
		s.pop();
	}
	else if (op == "size")
	{
		cout << s.size() << endl;
	}
	else if (op == "empty")
	{
		if (s.empty())
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else
	{
		if (s.size() == 0)
		{
			cout << -1 << endl;
			return;
		}
		else
		{
			cout << s.top() << endl;
		}
	}
}
int main()
{
	int test_case;
	cin >> test_case;
	string op;
	int num=0;
	for (int i = 0; i < test_case; i++)
	{
		cin >> op;
		if (op == "push")
		{
			cin >> num;
		}
		Dostack(op,num);
	}
	return 0;
}