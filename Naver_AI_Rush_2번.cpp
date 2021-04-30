#include<iostream>
#include<string>
#include<vector>

using namespace std;

string solution(string sentence, string keyword, vector<int> skips)
{
	string answer = "";
	int skips_idx = 0;
	int keyword_idx = 0;
	int sentence_idx = 0;
	for(int i=0;i<skips.size();i++)
	{
		int pass = skips[skips_idx];
		for (int j = 0; j < pass; j++)
		{
			if (keyword[keyword_idx] == sentence[sentence_idx])
			{
				answer += sentence[sentence_idx];
				sentence_idx++;
				break;
			}
			else
			{
				if (sentence_idx >= sentence.size())
				{
					break;
				}
				else
				{
					answer += sentence[sentence_idx];
					sentence_idx++;
				}
			}
		}
		answer += keyword[keyword_idx];
		keyword_idx++;
		if (keyword_idx >= keyword.size())
		{
			keyword_idx = 0;
		}
		skips_idx++;
	}
	for (int i = sentence_idx; i < sentence.size(); i++)
	{
		answer += sentence[i];
	}
	return answer;
}

int main()
{
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(3);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(0);
	temp.push_back(3);
	temp.push_back(0);
	temp.push_back(2);
	temp.push_back(4);
	temp.push_back(1);
	temp.push_back(3);
	string aa = solution("encrypt this sentence", "something", temp);
	cout << aa;
}