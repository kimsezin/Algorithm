#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int N;
int board[15];
int result = 0;
bool isOK(int _y)
{
	for (int pre_y = 0; pre_y < _y; pre_y++)
	{
		if (board[pre_y] == board[_y] or abs(board[pre_y] - board[_y]) == abs(pre_y - _y))
		{
			return false;
		}
	}
	return true;
}
void dfs(int _y)
{
	if (_y == N)
	{
		result++;
	}
	else
	{
		for (int _x = 0; _x < N; _x++)
		{
			board[_y] = _x;
			if (isOK(_y))
			{
				dfs(_y + 1);
			}
		}
	}
}
int main()
{
	cin >> N;
	dfs(0);
	cout << result;
}