#include <string>
#include <vector>
#include<iostream>;
using namespace std;

string solution(string new_id) {
    string answer = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] >= 'A' and new_id[i] <= 'Z')
        {
            new_id[i] += ('a' - 'A');
            continue;
        }
    }
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] != '-' and new_id[i] != '_' and new_id[i] != '.')
        {
            if (new_id[i] < 'a' or new_id[i] > 'z')
            {
                new_id.erase(i, 1);
                i--;
                continue;
            }
        }
    }
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] == '.' and new_id[i + 1] == '.')
        {
            while (new_id[i + 1] == '.')
            {
                new_id.erase((i + 1), 1);
                continue;
            }
        }
    }
    for (int i = 1; i < new_id.size(); i++)
    {
        if (new_id[i] == '.' and new_id[i - 1] == '.')
        {
            while (new_id[i - 1] == '.')
            {
                new_id.erase(i - 1, 1);
                i--;
                continue;
            }
        }
    }
    while(new_id[0] == '.')
    {
        new_id.erase(0, 1);
    }
    while (new_id[new_id.size()-1] == '.')
    {
        new_id.erase(new_id.size() - 1, 1);
    }
    if (new_id == "")
    {
        new_id = " ";
    }
    if (new_id.size() >= 15)
    {
        for (int i = 15; i < new_id.size(); i++)
        {
            new_id.erase(i,1);
            i--;
        }
    }
    if (new_id.size() <= 2)
    {
        int idx = new_id.size() - 1;
        for (int i = 0; i < 3; i++)
        {
            if (new_id.size() == 3)
            {
                break;
            }
            new_id += new_id[idx];
        }
    }

    return new_id;
}

int main()
{
    string new_id;
    cin >> new_id;
    new_id = solution(new_id);
    cout << new_id;
    return 0;
}