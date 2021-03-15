#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;

int L, C;
vector<char> password;
vector<string> result;

void solve(int _pos, string _temp, int _mo, int _ja)
{
	if (_temp.size() == L)
	{
		if (_mo >= 1 and _ja >= 2)
		{
			result.push_back(_temp);
			return;
		}
	}
	for (int i = _pos; i < C; i++)
	{
		if (password[i] == 'a' || password[i] == 'u' || password[i] == 'i' ||
			password[i] == 'o' || password[i] == 'e')
		{
			
			solve(i + 1, _temp + password[i] , _mo + 1, _ja);
		}
		else
		{
			solve(i + 1, _temp + password[i] , _mo, _ja + 1);
		}
	}
}
int main()
{
	cin >> L >> C;
	char data;
	for (int i = 0; i < C; i++)
	{
		cin >> data;
		password.push_back(data);
	}
	sort(password.begin(), password.end());


	solve(0,"",0,0);
	for (auto e : result)
	{
		cout << e << endl;
	}
	return 0;
}