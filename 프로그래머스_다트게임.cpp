#include <string>
#include<vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int temp = 0;
    vector<int> dart;
    int idx = 0;
    dart.push_back(0);
    dart.push_back(0);
    dart.push_back(0);
    for (int i = 0; i < dartResult.size(); i++)
    {
        int cnt = 0;
        if (dartResult[i] >= '0' and dartResult[i] <= '9')
        {
            temp = dartResult[i] - '0';
            if (dartResult[i + 1] >= '0' and dartResult[i + 1] <= '9')
            {
                i++;
                temp = 10;
            }
            if (dartResult[i + 1] == 'S')
            {
                cnt = 1;
            }
            if (dartResult[i + 1] == 'D')
            {
                temp = temp * temp;
                cnt = 1;
            }
            if (dartResult[i + 1] == 'T')
            {
                temp = temp * temp * temp;
                cnt = 1;
            }

            if (dartResult[i + 2] == '*')
            {
                if (idx > 0)
                {
                    dart[idx - 1] *= 2;
                    temp *= 2;
                }
                else
                {
                    temp *= 2;
                }
                cnt = 2;
            }
            else if (dartResult[i + 2] == '#')
            {
                temp = temp * (-1);
                cnt = 2;
            }
           
        }
        dart[idx] = temp;
        idx++;
        i += cnt;
    }
    for (int i = 0; i < 3; i++)
    {
        answer += dart[i];
    }
    return answer;
}

int main()
{
    string s = "1S*2T*3S";
    solution(s);
}