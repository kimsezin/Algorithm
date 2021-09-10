#include<iostream>
#include<vector>

using namespace std;
int computers;
int N;
vector<vector<int>> input(101, vector<int>(101, 0));
vector<bool> visited(101,false);
int cnt = -1;

void doDFS(int x)
{
	visited[x] = true;
	cnt++;

	for (int i = 1; i <= computers; i++)
	{
		if (visited[i] == true || input[x][i] == 0)
		{
			continue;
		}
		else
			doDFS(i);
	}
}
int main()
{
	cin >> computers >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		input[x][y] = 1;
		input[y][x] = 1;
	}
	doDFS(1);
	cout << cnt;
	return 0;
}