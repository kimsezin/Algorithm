#include<iostream>
#include<map>
#include <string>
using namespace std;
map<int, string> m;
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string temp;
		cin >> temp;
		m[i] = temp;
	}
	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9')
		{
			cout << m[stoi(temp)] <<endl;
		}
		else
		{
			for (int j = 1; j <=N; j++)
			{
				if (m[j] == temp)
				{
					cout << j << endl;
				}
			}
		}
	}
}