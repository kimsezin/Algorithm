#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int result = 0;
    int zero_cnt = 0;
    bool check = false;
    map<int, int> m1;
    m1[6] = 1;
    m1[5] = 2;
    m1[4] = 3;
    m1[3] = 4;
    m1[2] = 5;
    m1[1] = 6;
    m1[0] = 6;

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zero_cnt++;
        }

        auto match = find(lottos.begin(), lottos.end(), win_nums[i]);
        if (match != lottos.end())
        {
            result++;
        }
    }
    answer.push_back(m1[result + zero_cnt]);
    answer.push_back(m1[result]);
    return answer;
}

int main()
{
    solution({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 });
}