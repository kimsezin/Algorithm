#include<iostream>
#include<vector>
#include<algorithm>

#define INF 99999999
using namespace std;
int table[101][101];
int distance[101][101];
int n, m;


void doFloid()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (table[j][k] > table[i][k] + table[j][i])
				{
					table[j][k] = table[i][k] + table[j][i];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (table[i][j]==INF)
				cout << 0 << " ";
			else
				cout << table[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	cin >> n >> m;
	int from, to, cost;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (i == j)
				table[i][j] = 0;
			else
				table[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> from >> to >> cost;
		table[from][to] = min(cost, table[from][to]);
	}
	doFloid();
}