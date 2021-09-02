#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<vector<int>> scores) {
    vector<int> result;
    string answer;
    for (int i = 0; i < scores.size(); i++)
    {
        vector<int> temp = scores[i];
        int self_score = temp[i];
        int _max = -1, _min = 101;

        int size = temp.size();
        int sum = 0;
        float avg = 0;
        for (int j = 0; j < temp.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            if (scores[j][i] >= _max)
            {
                _max = scores[j][i];
            }
            if (scores[j][i] <= _min)
            {
                _min = scores[j][i];
            }
            sum += scores[j][i];
        }

        if (self_score > _max || self_score < _min)
        {
            avg = sum / (size - 1);
        }
        else
        {
            sum += self_score;
            avg = sum / size;
        }
        result.push_back(avg);
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] >= 90)
        {
            answer += "A";
        }
        else if (result[i] >= 80)
        {
            answer += "B";
        }
        else if (result[i] >= 70)
        {
            answer += "C";
        }
        else if (result[i] >= 50)
        {
            answer += "D";
        }
        else
        {
            answer += "F";
        }
    }
    return answer;
}

int main()
{
    solution({ {100, 90, 98, 88, 65},{50, 45, 99, 85, 77},{47, 88, 95, 80, 67},{61, 57, 100, 80, 65},{24, 90, 94, 75, 65} });
}