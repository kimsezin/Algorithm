#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>

using namespace std;
int T, k;



void solve(int _k)
{	
	multiset<int> q;
	for (int i = 0; i < _k; i++)
	{
		int input;
		char type;
		cin >> type >> input;
		if (type == 'I')
		{
			q.insert(input);
		}
		else
		{
			if (!q.empty())
			{
				if (input == 1)
				{
					auto temp = q.end();
					temp--;
					q.erase(temp);
				}
				else
				{
					q.erase(q.begin());
				}
			}
		}
	}
	if (q.empty())
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		auto temp = q.end();
		temp--;
		cout << *temp << " " << *q.begin() << endl;
	}
}
int main()
{
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		cin >> k;
		solve(k);
	}
	return 0;
}