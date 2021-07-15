#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> n3;
    while (n > 3)
    {
        n3.push_back(n % 3);
        n = n / 3;
        if (n <= 3)
        {
            n3.push_back(n % 3);
        }
    }
    int idx = 0;
    for (int i = n3.size(); i >= 1; i--)
    {
        int temp = 1;
        for (int j = 1; j < i; j++)
        {
            temp = temp * 3;
        }
        answer = answer + (temp * n3[idx]);
        idx++;
    }
    return answer;
}

int main()
{
    solution(45);
}