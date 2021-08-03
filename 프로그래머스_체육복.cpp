#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> greedy(n, 1);
    for (int i = 0; i < lost.size(); i++)
    {
        greedy[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        greedy[reserve[i] - 1]++;
    }
    for (int i = 0; i < greedy.size(); i++)
    {
        if (greedy[i] == 0)
        {
            if (i != 0 && greedy[i - 1] == 2)
            {
                greedy[i]++;
                greedy[i - 1]--;
            }
            else if (i != greedy.size() - 1 && greedy[i + 1] == 2)
            {
                greedy[i]++;
                greedy[i + 1]--;
            }
        }
    }
    for (int i = 0; i < greedy.size(); i++)
    {
        if (greedy[i] == 1)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    solution(5, { 2,4 }, { 1,3,5 });
}