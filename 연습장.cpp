#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N, M;

vector<int> result;
vector<vector<int>> map;
struct info
{
	int x, y, cnt;
};
int BFS(int x, int y, int cnt, vector<vector<bool>> visited)
{
	queue<info> q;
	q.push({ 0,0,1 });
	visited[0][0] = 1;

	while (!q.empty())
	{
		int nx = q.front().x;
		int ny = q.front().y;
		int n_cnt = q.front().cnt;

		q.pop();

		if (nx == N - 1 && ny == N - 1)
		{
			return n_cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			int Tx = nx + dx[i];
			int Ty = ny + dy[i];
			if (Tx >= 0 && Ty >= 0 && Tx < N && Ty < M)
			{
				if (visited[Tx][Ty] == 0 && map[Tx][Ty] == 1)
				{
					visited[Tx][Ty] = 1;
					q.push({ Tx, Ty, n_cnt + 1 });
				}

			}
		}
	}
	return -1;
}

int solution(vector<vector<int>> maps)
{
	int answer = 0;
	map = maps;

	int x = 0, y = 0, cnt = 1;

	N = maps.size();
	M = maps[0].size();
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	return BFS(0, 0, 1, visited);
}

int main()
{
	solution({ {1, 0, 1, 1, 1
}, { 1, 0, 1, 0, 1
}, { 1, 0, 1, 1, 1
}, { 1, 1, 1, 0, 1
}, { 0, 0, 0, 0, 1
} });
}