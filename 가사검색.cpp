#include<iostream>
#include<string>
#include<iterator>
#include<vector>
using namespace std;

string words[100000];
string queries;
int result[5];
int res_idx = 0;
void solve()
{
	int cnt = 0;
	int idx = 0;
	for (int i = 0; i < queries.size(); i++)
	{
		if (queries[i] == '?')
		{
			idx = i;
			break;
		}
	}
	for (int i = idx; i < queries.size(); i++)
	{
		if (queries[i] == '?')
		{
			cnt++;
		}
	}
	string temp;
	if (idx != 0)
	{
		for (int i = 0; i < idx; i++)
		{
			temp += queries[i];
		}
	}
	else
	{
		for (int i = cnt; i < queries.size(); i++)
		{
			temp += queries[i];
		}
	}
	int res_cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		if (words[i].size() == queries.size())
		{
			string temp_2;
			if (idx == 0)
			{
				for (int j = cnt; j < queries.size(); j++)
				{
					temp_2 += words[i][j];
				}
				if (temp == temp_2)
				{
					res_cnt++;
				}
			}
			else
			{
				for (int j = 0; j < queries.size() - cnt; j++)
				{
					temp_2 += words[i][j];
				}
				if (temp == temp_2)
				{
					res_cnt++;
				}
			}
		}
	}
	result[res_idx] = res_cnt;
	res_idx++;

}
int main()
{
	for (int i = 0; i < 6; i++)
	{
		string data;
		cin >> data;
		words[i] = data;
	}
	for (int i = 0; i < 5; i++)
	{
		cin >> queries;
		solve();
	}

	for (int i = 0; i < 5; i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}