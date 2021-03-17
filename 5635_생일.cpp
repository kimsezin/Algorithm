#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int N;


struct Info
{
	string name;
	int day;
	int month;
	int year;
};
Info information[100];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> information[i].name >> information[i].day >>
			information[i].month >> information[i].year;
	}
	
	int min = 2010;
	for (int i = 0; i < N; i++)
	{

	}
	
	
	return 0;
}