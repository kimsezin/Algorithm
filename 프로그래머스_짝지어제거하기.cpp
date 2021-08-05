#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        if (stack.empty())
        {
            stack.push(s[i]);
        }
        else
        {
            if (s[i] == stack.top())
            {
                stack.pop();
            }
            else
            {
                stack.push(s[i]);
            }
        }
    }
    if (stack.empty())
    {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    solution("baabaa");
}