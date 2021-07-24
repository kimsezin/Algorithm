#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> result;
    for (int i = 1; i <= 10; i++)
    {
        result.push_back(n % 10);
        n /= 10;
        if (n < 10)
        {
            result.push_back(n);
            break;
        }
    }
    sort(result.begin(), result.end());
    for (int i = result.size() - 1; i > 0; i--)
    {
        answer += result[i];
        if (i == 1)
        {
            break;
        }
        answer *= 10;

    }
    return answer;
}

int main()
{
    solution(1);
}