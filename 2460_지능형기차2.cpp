#include<iostream>

using namespace std;
int max_value = 0;
int cnt = 0;
int main()
{
	int input, output;
	for (int i = 0; i < 10; i++)
	{
		cin >> output >> input;
		cnt -= output;
		cnt += input;

		if (max_value < cnt)
		{
			max_value = cnt;
		}
	}
	cout << max_value;
	return 0;
}