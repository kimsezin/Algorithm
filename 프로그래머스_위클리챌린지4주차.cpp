#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string, int> result; // 각 분야별 최종 점수 저장용
    result["CONTENTS"] = 0;
    result["GAME"] = 0;
    result["HARDWARE"] = 0;
    result["PORTAL"] = 0;
    result["SI"] = 0;

   
    for (int i = 0; i < table.size(); i++)
    {
        map<string, int> score; // 분야별 선호 점수 저장용
        string temp = table[i];
        string buffer;
        istringstream ss(temp);
     
        getline(ss, buffer, ' ');
        string name = buffer; // 분야 이름 저장용

        int property = 5;
        while (getline(ss, buffer, ' '))
        {
            score[buffer] = property;
            property--;
        }
        for (int j = 0; j < languages.size(); j++)
        {
            result[name] += score[languages[j]] * preference[j];
        }
        
    }
    int max_value = 0;
    for (auto a = result.begin(); a != result.end(); a++)
    {
        if (max_value < a->second)
        {
            max_value = a->second;
            answer = a->first;
        }
    }
    return answer;
}

