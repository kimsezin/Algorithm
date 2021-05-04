#include<iostream>
#include<stack>

using namespace std;
stack<pair<int, int>> s;

int N;
int height;
int max_top = 0;
void solve()
{
	for (int i = 0; i < N; i++)
	{
		cin >> height;
		while (!s.empty())
		{
			if (height < s.top().second)
			{
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}

		if (s.empty())
		{
			cout << 0 << " ";
		}
		s.push({ i + 1,height });
	}
}

int main()
{
	cin.tie(0);
	cin >> N;

	solve();
	return 0;
}