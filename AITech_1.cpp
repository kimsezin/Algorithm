#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
	int tank[5];
	int m;

	
	for (int i = 0; i < 5; i++)
	{
		cin >> tank[i];
	}
	sort(tank,tank+5);


	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += tank[i];
	}
	cout << sum;
	return 0;
}