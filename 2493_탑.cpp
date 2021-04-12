#include<iostream>
#include<queue>
#include<iterator>
using namespace std;
int N;
vector<int> top;
vector<int>::iterator it;
int result[500000];
void solve()
{
	while (!top.empty())
	{
		int cur_top = *(top.end() - 1);
		int idx = top.size() - 1;
		top.erase(top.end() - 1);

		for (int i = top.size() - 1; i >= 0; i--)
		{
			if (top[i] > cur_top)
			{
				result[idx] = i + 1;
				break;
			}
		}
	}

	for (int i = 0; i<N; i++)
	{
		cout << result[i] << " ";
	}
}
int main()
{
	cin >> N;
	int height;
	for (int i = 0; i < N; i++)
	{
		cin >> height;
		top.push_back(height);
	}

	solve();
	
}