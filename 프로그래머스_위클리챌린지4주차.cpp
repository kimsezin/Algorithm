#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string, int> result; // �� �оߺ� ���� ���� �����
    result["CONTENTS"] = 0;
    result["GAME"] = 0;
    result["HARDWARE"] = 0;
    result["PORTAL"] = 0;
    result["SI"] = 0;

   
    for (int i = 0; i < table.size(); i++)
    {
        map<string, int> score; // �оߺ� ��ȣ ���� �����
        string temp = table[i];
        string buffer;
        istringstream ss(temp);
     
        getline(ss, buffer, ' ');
        string name = buffer; // �о� �̸� �����

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

