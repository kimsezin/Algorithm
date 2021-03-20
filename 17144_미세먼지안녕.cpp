#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int R, C, T;
int map[51][51];
int copy_map[51][51];

int clear_up_x=-1;
int clear_up_y=-1;
int clear_down_x=-1;
int clear_down_y=-1;

int type = 0;


bool Down_check_down = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void init()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				if (clear_up_x == -1 and clear_up_y == -1)
				{
					clear_up_x = i;
					clear_up_y = j;
				}

				else
				{
					clear_down_x = i;
					clear_down_y = j;
				}
			}
		}
	}
}
int cnt = 0;
void solve()
{
	for (int x = 0; x < R; x++)
	{
		for (int y = 0; y < C; y++)
		{
			if (x == clear_up_x and y == clear_up_y)
			{
				continue;
			}
			if (x == clear_down_x and y == clear_down_y)
			{
				continue;
			}
			int size = map[x][y];
			int spread_size = map[x][y] / 5;
			int cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 or nx >= R or ny < 0 or ny >= C)
				{
					continue;
				}
				if (map[nx][ny] == -1)
				{
					continue;
				}
				cnt++;
				copy_map[nx][ny] += spread_size;
			}
			map[x][y] -= (cnt * spread_size);
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			map[i][j] += copy_map[i][j];
			copy_map[i][j] = 0;
		}
	}
}

void clear() {

	
	for (int i = clear_up_x - 1; i >= 1; i--) {
		map[i][0] = map[i - 1][0];
	}
	// 우측에서 좌측으로
	for (int i = 0; i < C - 1; i++) {
		map[0][i] = map[0][i + 1];
	}
	// 아래에서 위
	for (int i = 0; i < clear_up_x; i++) {
		map[i][C - 1] = map[i + 1][C - 1];
	}
	// 좌에서 우
	for (int i = C - 1; i >= 1; i--) {
		map[clear_up_x][i] = map[clear_up_x][i - 1];
	}
	// 정화 공기로 채워진 장소
	map[clear_up_x][1] = 0;


	// 아래방향 순환
	// 아래에서 위 방향으로
	for (int i = clear_up_x + 2; i < R - 1; i++) {
		map[i][0] = map[i + 1][0];
	}
	// 좌측에서 우측으로
	for (int i = 0; i < C - 1; i++) {
		map[R - 1][i] = map[R - 1][i + 1];
	}
	// 위에서 아래
	for (int i = R - 1; i > clear_up_x + 1; i--) {
		map[i][C - 1] = map[i - 1][C - 1];
	}
	// 좌에서 우
	for (int i = C - 1; i >= 1; i--) {
		map[clear_up_x + 1][i] = map[clear_up_x + 1][i - 1];
	}
	// 정화 공기로 채워진 장소
	map[clear_up_x + 1][1] = 0;
}
int main()
{
	cin >> R >> C >> T;
	init();
	for (int i = 0; i < T; i++)
	{
		solve();
		/*for (int k = 0; k < R; k++)
		{
			for (int q = 0; q < C; q++)
			{
				cout << map[k][q] << " ";
			}
			cout << endl;
		}*/
		clear();
	}
	int result = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != -1)
			{
				result += map[i][j];
			}
		}
	}
	cout << result;

	
	return 0;
}