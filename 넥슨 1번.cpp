#include<iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solve(int X, vector<int> arr, vector<int> query_values) {
    vector<int> answer;
    map<int, int> map;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == X)
        {
            cnt++;
            map[cnt] = i+1;
        }
    }

    for (int i = 0; i < query_values.size(); i++)
    {
        answer.push_back(map[query_values[i]]);
    }
    for (int i = 0; i < query_values.size(); i++)
    {
        if (answer[i] == 0)
            answer[i] = -1;
    }
    return answer;
}

int main()
{
    solve(8, { 1,2,20,8,8,1,2,5,8,0 }, { 100,2,1,3,4 });
}