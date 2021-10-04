#include <string>
#include <vector>
#include<map>
#include <iostream>
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

    string check = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            temp += s[i];
        }
        else
        {
            check += s[i];
            for (int i = 0; i <= 9; i++)
            {
                if (map[i] == check)
                {
                    check = "";
                    temp += map[i];
                }
            }

        }
    }
    answer = stoi(temp);
    return answer;
}

int main()
{
    solution("one4seveneight");
}