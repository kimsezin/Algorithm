#include<iostream>
#include<vector>

using namespace std;


int test_case;
int M, N, K, X, Y;
vector<vector<int>> map(51, vector<int>(51, 0));
vector<vector<int>> visited(51, vector<int>(51, 0));
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;
void doDFS(int x, int y)
{
	visited[x][y] = 1;


	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ( nx >= 0 && nx < M && ny >= 0 && ny < N )
		{
			if(map[nx][ny] == 1 && visited[nx][ny] == 0)
			doDFS(nx, ny);
		}
	}
}
int main()
{
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		cnt = 0;
		map = vector<vector<int>>(51, vector<int>(51, 0));
		visited = vector<vector<int>>(51, vector<int>(51, 0));
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (map[j][k] == 1 && visited[j][k] == 0)
				{
					cnt++;
					doDFS(j, k);
				}
			}
		}
		cout << cnt << endl;
	}
	

	return 0;
}