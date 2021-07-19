#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p_cnt=0, y_cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'p' || s[i] == 'P')
        {
            p_cnt++;
        }
        else if (s[i] == 'y' || s[i] == 'Y')
        {
            y_cnt++;
        }
    }

    if (p_cnt == 0 and y_cnt == 0)
    {
        return answer;
    }
    if (p_cnt == y_cnt)
    {
        return answer;
    }
    else
    {
        answer = false;
        return answer;
    }

    return answer;
}

int main()
{
    string s = "pPoooyY";
    solution(s);
}