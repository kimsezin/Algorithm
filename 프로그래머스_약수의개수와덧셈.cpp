#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    bool check[1001] = { true, };
    for (int i = left; i <= right; i++)
    {
        int cnt = 0;
        for (int j = 2; j <= i; j += j)
        {
            if (check[j] == false)
            {
                if (i % j == 0)
                {
                    check[j] = true;
                    cnt++;
                }
            }
        }
        if (cnt % 2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }
    return answer;
}

int main()
{
    solution(24, 27);
}