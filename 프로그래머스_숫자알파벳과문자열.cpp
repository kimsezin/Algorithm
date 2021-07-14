#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            answer = answer * 10 + (s[i] - '0');
        }
        else
        {
            if (s[i] == 'z')
            {
                answer *= 10;
                i = i + 3;
            }
            else if (s[i] == 'o')
            {
                answer = answer * 10 + 1;
                i = i + 2;
            }
            else if (s[i] == 't')
            {
                if (s[i + 1] == 'w')
                {
                    answer = answer * 10 + 2;
                    i = i + 2;
                }
                else if (s[i + 1] = 'h')
                {
                    answer = answer * 10 + 3;
                    i = i + 4;
                }
            }
            else if (s[i] == 'f')
            {
                if (s[i + 1] == 'o')
                {
                    answer = answer * 10 + 4;
                    i = i + 3;
                }
                else if (s[i + 1] == 'i')
                {
                    answer = answer * 10 + 5;
                    i = i + 3;
                }
            }
            else if (s[i] == 's')
            {
                if (s[i + 1] == 'i')
                {
                    answer = answer * 10 + 6;
                    i = i + 2;
                }
                else if (s[i + 1] == 'e')
                {
                    answer = answer * 10 + 7;
                    i = i + 4;
                }
            }
            else if (s[i] == 'e')
            {
                answer = answer * 10 + 8;
                i = i + 4;
            }
            else if (s[i] == 'n')
            {
                answer = answer * 10 + 9;
                i = i + 3;
            }
        }
    }
    return answer;
}