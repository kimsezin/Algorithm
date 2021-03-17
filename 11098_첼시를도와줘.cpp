#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int n;
int p;

int main()
{
	cin >> n ;
	string name;
	
	long long price;
	for (int i = 0; i < n; i++)
	{
		vector<pair<long long, string>> agent;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			cin >> price >> name;
			agent.push_back({ price,name });
		}
		sort(agent.begin(), agent.end());
		cout <<  agent.back().second << endl;
	}
	return 0;
}