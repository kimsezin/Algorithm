#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int check = 0;
    int full = str1.size() - 1;

    vector<string> check1;
    vector<string> check2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
        {
            check1.push_back(str1.substr(i, 2));
        }
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
        {
            check2.push_back(str2.substr(i, 2));
        }
    }
    for (int i = 0; i < check1.size(); i++)
    {
        for (int j = 0; j < check2.size(); j++)
        {
            if (check1[i] == check2[j])
            {
                check++;
                check2.erase(check2.begin() + j);
            }
        }
    }
    float result = full / check;
    answer = (int)result * 65536;
    return answer;
}

int main()
{
    solution("FRANCE", "french");
}