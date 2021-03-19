#include<iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	int sum = 0;
	float gpa_sum = 0.0;
	float gpa;
	int num;
	for (int j = 0; j < n; j++)
	{
		cin >> num >> gpa;
		sum += num;
		gpa_sum += (num * gpa);
	}
	cout << fixed;
	cout.precision(0);
	cout << sum;
	cout.precision(1);
	cout << " " << gpa_sum / sum << '\n';
}
int main()
{
	
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	solve();

	return 0;
}