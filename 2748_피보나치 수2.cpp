#include<iostream>

using namespace std;

long long result[100];
int idx = 1;
int N;
void solve()
{
	while (idx < N)
	{
		result[idx + 1] = result[idx] + result[idx - 1];
		idx++;
	}
}
int main()
{
	cin >> N;
	result[0] = 0;
	result[1] = 1;
	solve();
	cout << result[N];
	return 0;
}