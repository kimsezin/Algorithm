#include<iostream>
#include<string>
using namespace std;

string data1, data2;
int main()
{
	cin >> data1 >> data2;
	int temp1, temp2;
	
	temp1 = (data1[2] - '0') * 100;
	temp1 += (data1[1] - '0') * 10;
	temp1 += data1[0] - '0';
	temp2 = (data2[2] - '0') * 100;
	temp2 += (data2[1] - '0') * 10;
	temp2 += data2[0] - '0';

	if (temp1 > temp2)
	{
		cout << temp1;
	}
	else
		cout << temp2;
	
	return 0;
}