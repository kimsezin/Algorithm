#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    int cnt = 0;
    while (cnt < s.size())
    {
        if (s[cnt] == ' ')
        {
            idx = cnt+1;
        }
        else
        {
            if (cnt % 2 == 1)
            {
                if (s[idx] >= 'A' and s[idx] <= 'Z')
                {
                    s[idx] = s[idx] - 'A' + 'a';
                }
                idx++;
            }
            else
            {
                if (s[idx] >= 'a' and s[idx] <= 'z')
                {
                    s[idx] = s[idx] - 'a' + 'A';
                }
                idx++;
            }
        }
        cnt++;
    }
    return s;
}
int main()
{
    string s = "try hello world"
        ;
    solution(s);
}