#include<iostream>

using namespace std;
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2.2, -2,2, -1,1 };
int K;
int W, H;
int map[201][201];
void Monkey(int _K)
{
	for (int i = 0; i < K; i++)
	{

	}
}
int main()
{
	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < 201; j++)
		{
			map[i][j] = 999999;
		}
	}
	cin >> K;
	cin >> W >> H;

	for (int i = 1; i <= W; i++)
	{
		for (int j = 1; j <= H; j++)
		{
			cin >> map[i][j];
		}
	}
	Monkey(K);

	return 0;
}