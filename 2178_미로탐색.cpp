#include<iostream>
#include<queue>
#include<string>
using namespace std;

int MIRO(int N, int M)
{
	char miro[101][101] = { '0', };
	string input;
	scanf("%s", &input);
	int _index = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			miro[i][j] = input[_index];
			_index = _index + 1;
		}
	}

	queue<pair<int, int>> q;
	
	while (!q.empty())
	{
	
		int curLoc = q.front().first;
		int curCnt
	}

}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int result;
	if (2 <= N <=100 and 2 <= M <= 100)
	{
		result = MIRO(N, M);
	}

	printf("%d", result); 
	return 0;
}