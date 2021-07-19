#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int Answer;
void fr(int frnd[],int num, int cnt,int i)
{
	
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	int T, test_case;
	
	bool check[100001];
	cin >> T;
	
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 1;
		int num;
		int natural;
		scanf("%d", &num);

		int D[100000];
		int frnd[100000];
		for (int i = 1; i <= num; i++)
		{
			scanf("%d", &D[i]);
			frnd[i] = i;
		}

		for (int i = 1; i <= num; i++)
		{
			int cnt = i + D[i];
			if (cnt > num)
			{
				continue;
			}
			for (int j = 1; j <= num; j++)
			{
				if (frnd[j] == frnd[cnt])
				{
					frnd[j] = frnd[i];
				}
			}
			
		}
		cout << "Case #" << test_case + 1 << endl;
		sort(&frnd[1], &frnd[num+1]);
		for (int i = 1; i < num; i++)
		{
			if (frnd[i] != frnd[i + 1])
			{
				Answer += 1;
			}
		}
		cout << Answer << endl;
	}

	return 0;
}