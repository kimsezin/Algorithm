#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
   
    vector<int> result;
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> answer;
        int start = commands[i][0];
        int end = commands[i][1];
        int k = commands[i][2] - 1;

        for (int j = start - 1; j <= end - 1; j++)
        {
            answer.push_back(array[j]);
        }
        sort(answer.begin(), answer.end());

        result.push_back(answer[k]);

    }
    return result;
}

int main()
{
    vector<int> array;
    vector<vector<int>> commands(3);
    int temp;
    for (int i = 0; i < 7; i++)
    {
        
        cin >> temp;
        array.push_back(temp);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> temp;
            commands[i].push_back(temp);
        }
    }
    vector<int> a = solution(array, commands);
    return 0;
}