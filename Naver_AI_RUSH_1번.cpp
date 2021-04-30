#include<iostream>
#include<algorithm>
#include<vector>
#include<vector>

using namespace std;

vector<vector<int>> score(10, vector<int>(10,0));


int N;

string solution(vector<vector<int>> scores)
{
	string answer;
	vector<int> total;
	for (int i = 0; i < scores[i].size(); i++)
	{
		int sum = 0;
		int max_score = 0;
		int min_score = 101;
		int num = N;
		for (int j = 0; j < scores[i].size(); j++)
		{
			if (max_score < scores[i][j])
			{
				max_score = scores[i][j];
			}
			if(min_score > scores[i][j])
			{
				min_score = scores[i][j];
			}
			sum += scores[i][j];
		}
		if (max_score == scores[i][i])
		{
			sum -= max_score;
			num -= 1;
		}
		if (min_score == scores[i][i])
		{
			sum -= min_score;
			num -= 1;
		}
		total.push_back(sum/num);
	}
	for (int i = 0; i < scores[i].size(); i++)
	{
		if (total[i] >= 90)
		{
			answer+='A';
		}
		else if (total[i] >= 80)
		{
			answer += 'B';
		}
		else if (total[i] >= 70)
		{
			answer += 'C';
		}
		else if (total[i] >= 50)
		{
			answer += 'D';

		}
		else
		{
			answer += 'F';
		}
	}
	return answer;
}
int main()
{
	cin >> N;
	vector<int> temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> score[i][j];
		}
	}
	solution(score);
}