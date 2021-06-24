#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
bool Cmp(pair<double, int> A, pair<double, int> B)
{
	if (A.first >= B.first)
	{
		if (A.first == B.first)
		{
			if (A.second < B.second)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<float, int>> lose;
	float clear_cnt = 0;
	float nonclear_cnt = 0;
	sort(stages.begin(), stages.end());
	for (int i = 1; i <= N; i++)
	{
		clear_cnt = 0;
		nonclear_cnt = 0;
		for (int j = 0; j < stages.size(); j++)
		{
			if (stages[j] == i)
			{
				nonclear_cnt++;
			}
			else if (stages[j] > i)
			{
				clear_cnt++;
			}
		}
		float f = nonclear_cnt / (nonclear_cnt + clear_cnt);
		lose.push_back({ nonclear_cnt / (nonclear_cnt + clear_cnt),i });
	}
	sort(lose.begin(), lose.end(),Cmp);
	for (int i =0 ;i < lose.size(); i++)
	{
		answer.push_back(lose[i].second);
	}
	return answer;
}

int main()
{
	int N;
	vector<int> stages;
	cin >> N;
	for (int i = 0; i < 5; i++)
	{
		int temp;
		cin >> temp;
		stages.push_back(temp);
	}
	vector<int> res = solution(N, stages);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
}