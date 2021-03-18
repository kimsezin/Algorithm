#include<iostream>
#include<vector> 
#include<iterator>
using namespace std;
void printNull()
{
	cout << " ";
}
void printStar()
{
	cout << "*";
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int j = N - i;
		for (int q = 0; q < i; q++)
		{
			printNull();
		}
		for (int k = 0; k < j; k++)
		{
			printStar();
		}
		
		if(i!=N-1)
		cout << endl;
	}
	
}