#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    map<int, string> map;

    map[0] = "zero";
    map[1] = "one";
    map[2] = "two";
    map[3] = "three";
    map[4] = "four";
    map[5] = "five";
    map[6] = "six";
    map[7] = "seven";
    map[8] = "eight";
    map[9] = "nine";

    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            temp += s[i];
            for (auto a = map.begin(); a != map.end(); a++)
            {   
                if (a->second == temp)
                {
                    s.erase(i - temp.size() + 1, temp.size() - 1);
                    s[i - temp.size()+1] = '0'+a->first;
                    i = i - temp.size();
                    temp = "";
                    break;
                }
            }
            
        }
    }
    answer = stoi(s);
    return answer;
}

int main()
{
    solution("2three45sixseven");
}