#include <string>
#include <vector>
#include<algorithm>
#include<map>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int avg = 0;
    vector<int> result(scores.size(),0);
    vector<bool> check(scores.size(), false);
    
    for (int i = 0; i < scores.size(); i++)
    {
        avg = 0;
        int cnt = scores.size();
        vector<int> temp = scores[i];
        vector<int> temp2 = scores[i];
        int self_score = temp[i];
        sort(temp.begin(), temp.end());

        if (self_score == temp[0])
        {
            if (temp[0] == temp[1])
            {
                for (int j = 0; j < temp.size(); j++)
                {
                    result[j] += temp2[j];
                }
            }
            else
            {
                for (int j = 0; j < temp.size(); j++)
                {
                    if (j == i)
                    {
                        continue;
                    }
                    else
                        result[j] += temp2[j];
                }
                check[i] = true;
            }
        }
        else if (self_score == temp[temp.size() - 1])
        {
            if (temp[temp.size() - 1] == temp[temp.size() - 2])
            {
                for(int j=0;j<temp.size();j++)
                result[j] += temp2[j];
            }
            else
            {
                for (int j = 0; j < temp.size(); j++)
                {
                    if (j == i)
                    {
                        continue;
                    }
                    else
                        result[j] += temp2[j];
                }
                check[i] = true;
            }
        }
        else
        {
            for (int j = 0; j < temp.size(); j++)
            {
                result[j] += temp2[j];
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (check[i] == false)
        {
            result[i] /= scores.size();
        }
        else
        {
            result[i] /= (scores.size()-1);
        }
        if (result[i] >= 90)
        {
            answer.push_back('A');
        }
        else if (result[i] >= 80)
        {
            answer.push_back('B');
        }
        else if (result[i] >= 70)
        {
            answer.push_back('C');
        }
        else if (result[i] >= 50)
        {
            answer.push_back('D');
        }
        else
        {
            answer.push_back('F');
        }
    }
    return answer;
}

int main()
{
    solution({ {100, 90, 98, 88, 65},{50, 45, 99, 85, 77},{47, 88, 95, 80, 67},{61, 57, 100, 80, 65},{24, 90, 94, 75, 65} });
}