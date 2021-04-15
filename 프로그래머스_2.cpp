#include <string>
#include <vector>
#include <stack>


using namespace std;
int answer = 0;



int x = 0;


int solution(string s) {
    while (x != s.size())
    {
        stack<char> s1;
        stack<char> s2;
        stack<char> s3;
        string s_copy = s;
        int end_idx = s.size() - 1;
        s[end_idx] = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            s[i - 1] = s_copy[i];
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                s1.push('(');
            }
            else if (s[i] == '{')
            {
                s2.push('{');
            }
            else if (s[i] == '[')
            {
                s3.push('[');
            }
            else if (s[i] == ')')
            {
                if (!s1.empty() && s1.top() == '(')
                {
                    s1.pop();
                }
                else
                {
                    s1.push(')');
                }
            }
            else if (s[i] == '}')
            {
                if (!s2.empty() && s2.top() == '{')
                {
                    s2.pop();
                }
                else
                {
                    s2.push('}');
                }
            }
            else if (s[i] == ']')
            {
                if (!s3.empty() && s3.top() == '[')
                {
                    s3.pop();
                }
                else
                {
                    s3.push(']');
                }
            }
        }

        if (s1.empty() && s2.empty() && s3.empty())
        {
            answer++;
        }
        x++;
        solution(s);
    }


    return answer;
}

int main()
{
    solution("[](){}");
}