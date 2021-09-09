#include<iostream>
#include<stack>
#include<string>

using namespace std;
string check_VPS(string VPS)
{
	stack<char> s;
	for (int i = 0; i < VPS.size(); i++)
	{
		if (VPS[i] == '(')
		{
			s.push('(');
		}
		else
		{
			if (s.empty())
			{
				return "NO";
			}
			else
			{
				s.pop();
			}
		}
	}
	if (s.empty())
		return "YES";
	else
		return "NO";
}
int main()
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		string VPS;
		cin >> VPS;
		cout << check_VPS(VPS)<<endl;
	}
}