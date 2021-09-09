#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> s;
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			s.pop();
		}
		else
		{
			s.push(temp);
		}
	}
	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
	
}