#include<iostream>

using namespace std;
int total;
int main()
{
	cin >> total;
	for (int i = 0; i < 9; i++)
	{
		int data;
		cin >> data;
		total -= data;
	}
	cout << total;
}