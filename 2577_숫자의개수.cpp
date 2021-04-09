#include<iostream>

using namespace std;
int cnt[10];
int main()
{
	int value = 1;
	int data;
	for (int i = 0; i < 3; i++)
	{
		cin >> data;
		value = value * data;
	}
	while (!(value < 10))
	{
		cnt[value % 10]++;
		value /= 10;
	}
	cnt[value]++;

	for (int i = 0; i < 10; i++)
	{
		cout << cnt[i] << endl;
	}
	return 0;
}