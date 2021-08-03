#include <string>
#include <vector>

using namespace std;

int cnt = 0;
void dfs(int i, vector<int>numbers, int target, int idx)
{
    if (idx == numbers.size()-1)
    {
        if (target == i)
        {
            cnt++;
        }
        return;
    }
    dfs(i + numbers[idx + 1], numbers, target, idx + 1);
    dfs(i - numbers[idx + 1], numbers, target, idx + 1);

}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int temp = numbers[0];
    dfs(temp, numbers, target, 0);
    dfs(-temp, numbers, target, 0);

    return cnt;
}

int main()
{
    solution({ 1,1,1,1,1 }, 3);
}