#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> res1, res2;
    for (int i = 0; i < n; i++)
    {
        int temp = arr1[i];
        for (int j = 0; j < n; j++)
        {
            res1.push_back(temp % 2);
            temp = temp / 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int temp = arr2[i];
        for (int j = 0; j < n; j++)
        {
            res2.push_back(temp % 2);
            temp = temp / 2;
        }
    }
    int length = n * n;
    vector<int> res;
    for (int i = 0; i < length; i++)
    {
        res.push_back(res1[i] + res2[i]);
    }
    for (int i = 0; i < n; i++)
    {
        string a="";
        for (int j = n-1; j >= 0; j--)
        {
            if (res[(i * n) + j] >= 1)
            {
                a+="#";
            }
            else
            {
                a += " ";
            }
        }
        answer.push_back(a);
        answer.push_back(", ");
    }
    return answer;
}

int main()
{
    int n = 5;
    vector<int> a = { 9, 20, 28, 18, 11 };
    vector<int> b = { 30, 1, 21, 17, 28 };
    solution(n, a, b);
}