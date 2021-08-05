#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;
bool check[9999999];
void checkprime(int x)
{
    if (x == 1 || x == 0)
    {
        return;
    }
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return;
        }
    }
    if (check[x] == false)
    {
        check[x] = true;
        cnt++;
    }
}
int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= numbers.size(); i++)
        {
            int x = stoi(numbers.substr(0, i));
            checkprime(x);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    return cnt;
}

int main()
{
    solution("011");
}