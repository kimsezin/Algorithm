#include<iostream>

using namespace std;

int N;
bool visited[31][31];
double percent[4];
int dx[4] = { 0,0,1,-1 };//µ¿¼­³²ºÏ
int dy[4] = { 1,-1,0,0 };
double result;
void solve(int _y, int _x, int _cnt, double _p)
{
	if (_cnt == N)
	{
		result += _p;
		return;
	}

	int ny, nx;
	for (int i = 0; i < 4; i++)
	{
		ny = _y + dy[i];
		nx = _x + dx[i];
		if (visited[ny][nx] == 0)
		{
			visited[ny][nx] = 1;
			solve(ny, nx, _cnt + 1, _p * percent[i]);
			visited[ny][nx] = 0;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		cin >> percent[i];
		percent[i] /= 100;
	}
	visited[15][15] = 1;
	solve(15,15,0,1.0);
	cout.precision(11);
	cout.fixed;
	cout << result;
	return 0;
}