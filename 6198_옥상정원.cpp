#include<iostream>
#include<stack>
using namespace std;

int N;
long long building[80000];
stack<long long> high;
long long cnt = 0;
void Benchmarking()
{
	for (int i = 0; i < N; i++)
	{
		while (!high.empty() && high.top() <= building[i])
		{
			high.pop();
		}
		high.push(building[i]);

		cnt = cnt + high.size() - 1;
	}
	cout << cnt << endl;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> building[i];
	}

	Benchmarking();
}