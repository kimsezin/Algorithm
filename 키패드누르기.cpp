#include <string>
#include<iostream>
#include <vector>
#include <math.h>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> left;
    vector<pair<int, int>> right;
    left.push_back({ 4,1 });
    right.push_back({ 4,3 });

    int left_x, left_y, right_x, right_y;
    left_x = left[0].first;
    left_y = left[0].second;
    right_x = right[0].first;
    right_y = right[0].second;


    int pad[5][4];
    int temp = 1;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            pad[i][j] = temp;
            temp++;
        }
    }
    pad[4][2] = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                if (pad[j][k] == numbers[i])
                {
                    if (numbers[i] == 1 or numbers[i] == 4 or numbers[i] == 7)
                    {
                        answer += "L";
                        left_x = j;
                        left_y = k;
                        continue;
                    }
                    else if (numbers[i] == 3 or numbers[i] == 6 or numbers[i] == 9)
                    {
                        answer += "R";
                        right_x = j;
                        right_y = k;
                        continue;
                    }
                    else if (abs(j - left_x) + abs(k - left_y) == abs(j - right_x) + abs(k - right_y))
                    {
                        if (hand == "left")
                        {
                            answer += "L";
                            left_x = j;
                            left_y = k;
                            continue;
                        }
                        else
                        {
                            answer += "R";
                            right_x = j;
                            right_y = k;
                            continue;
                        }
                    }
                    else if (abs(j - left_x) + abs(k - left_y) > abs(j - right_x) + abs(k - right_y))
                    {
                        answer += "R";
                        right_x = j;
                        right_y = k;
                        continue;
                    }
                    else
                    {
                        answer += "L";
                        left_x = j;
                        left_y = k;
                        continue;
                    }
                }
            }
        }

    }
    return answer;
}

int main()
{
    vector<int> a;
    
    string hand;
    for (int i = 0; i < 11; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cin >> hand;
    cout << solution(a, hand);


    return 0;
}