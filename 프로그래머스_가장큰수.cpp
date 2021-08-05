#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for (auto num : numbers)
    {
        temp.push_back(to_string(num));
    }
    sort(temp.begin(), temp.end(), cmp);
    for (auto num : temp)
    {
        answer += num;
    }
    return answer;
}
int main()
{
    solution({ 3,30,34,5,9 });
}