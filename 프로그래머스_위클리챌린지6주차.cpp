#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;


typedef struct
{
    int idx;
    int weight;
    int bigger_cnt;
    double win_avg;
}info;

bool cmp(info a, info b)
{
    if (a.win_avg > b.win_avg)
    {
        return true;
    }

    if (a.win_avg == b.win_avg)
    {
        if (a.bigger_cnt > b.bigger_cnt)
        {
            return true;
        }

        if (a.bigger_cnt == b.bigger_cnt)
        {
            if (a.weight > b.weight)
            {
                return true;
            }
            if (a.weight == b.weight && a.idx < b.idx)
            {
                return true;
            }
        }
    }
	/*if (a.win_avg == b.win_avg)
	{
		if (a.bigger_cnt == b.bigger_cnt)
		{
			return a.weight > b.weight;

		}
		else
		{
			return a.bigger_cnt > b.bigger_cnt;
		}
	}
	else
	{
		return a.win_avg > b.win_avg;
	}*/
}
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<info> result;
    vector<int> answer;
    for (int i = 0; i < weights.size(); i++)
    {
        info temp;
        temp.idx = i + 1;
        temp.weight = weights[i];
        temp.bigger_cnt = 0;
        temp.win_avg = 0;
        int total_cnt = 0;
        for (int j = 0; j < head2head[i].size(); j++)
        {
            if (head2head[i][j] == 'N')
            {
                continue;
            }
            total_cnt++;
            if (head2head[i][j] == 'W')
            {
                if (weights[i] < weights[j])
                {
                    temp.bigger_cnt++;
                }
                temp.win_avg++;
            }
        }
        if (total_cnt)
        {
            temp.win_avg = temp.win_avg / total_cnt;
        }
        else
        {
            temp.win_avg = 0;
        }
        result.push_back(temp);

    
    }
    sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < result.size(); i++)
    {
        answer.push_back(result[i].idx);
    }
    return answer;
}

int main(void)
{
    vector<int> weights = { 50,82,75,120 };
    vector<string> head2head = { "NLWL","WNLL","LWNW","WWLN" };
    vector<int> answers = solution(weights, head2head);
}

