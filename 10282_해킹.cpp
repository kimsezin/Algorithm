#include<iostream>
#include<vector>
using namespace std;
int T;

int infect; // 감염 컴퓨터 수
int infect_sec; // 마지막 컴퓨터가 감염되기까지 걸린 시간
int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n,d,c;
		cin >> n >> d >> c;

		vector<vector<pair<int, int>>> hack(n + 1);
		for (int j = 0; j < d; j++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			
			hack[b].emplace_back(a, s);
		}
		infect = 0;
		infect_sec = 0;
		solve(hack, c, n);
	}

	return 0;
}