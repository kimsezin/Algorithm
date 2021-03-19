#include<iostream>

using namespace std;
int prices[100000];
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int s;
		int n;
		cin >> s;
		cin >> n;
		int price = 0;
		for (int j = 0; j < n; j++)
		{
			int q, p;
			cin >> q;
			cin >> p;
			price += (p * q);
		}
		prices[i] = s + price;
	}
	for (int i = 0; i < t; i++)
	{
		cout << prices[i] << endl;
	}
	return 0;
}