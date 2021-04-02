#include<iostream>

using namespace std;

int N;
int cnt = 0;
int main()
{
	cin >> N;
	int data;
	for (int i = 0; i < N-1; i++)
	{
		
		cin >> data;
		cnt = cnt + (data - 1);
	}
	cin >> data;
	cnt = cnt + data;
	cout << cnt;
}