#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a1, a2, a3;
    for (int i = 0; i < 2000; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            a1.push_back(j);
        }
    }
    for (int i = 0; i < 1250; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (j != 2)
            {
                a2.push_back(2);
                a2.push_back(j);
            }
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        a3.push_back(3);
        a3.push_back(3);
        for (int j = 1; j <= 5; j++)
        {
            if (j != 3)
            {
                a3.push_back(j);
                a3.push_back(j);
            }
        }
    }
    vector<int> cnt;
    cnt.push_back(0);
    cnt.push_back(0);
    cnt.push_back(0);
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a1[i])
        {
            cnt[0]++;
        }
        if (answers[i] == a2[i])
        {
            cnt[1]++;
        }
        if (answers[i] == a3[i])
        {
            cnt[2]++;
        }
    }
    int temp = 0;
    int idx = 0;
    for (int i = 0; i < 3; i++)
    {
        if (temp < cnt[i])
        {
            idx = i;
            temp = cnt[i];
        }
    }
    answer.push_back(idx + 1);
    for (int i = 0; i < 3; i++)
    {
        if (i != idx)
        {
            if (cnt[i] == cnt[idx])
            {
                answer.push_back(i + 1);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    vector<int> b = solution(a);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i];
    }
}