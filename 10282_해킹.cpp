#include<iostream>
#include<vector>
using namespace std;
int T;

int infect; // ���� ��ǻ�� ��
int infect_sec; // ������ ��ǻ�Ͱ� �����Ǳ���� �ɸ� �ð�
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