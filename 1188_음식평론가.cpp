#include<iostream>

using namespace std;
int N, M;
int solve(int n, int m)
{
	n %= m;
	if (n == 0) return 0;
	
	return n + solve(n, m - n);
}
int main()
{
	cin >> N >> M;
	int answer = solve(N, M);
	cout << answer << endl;

	return 0;
}