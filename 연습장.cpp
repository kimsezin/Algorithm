#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answer;
vector<bool> visited;
bool dfs(string port, vector<vector<string>> tickets, int cnt)
{

}
vector<string> solution(vector<vector<string>> tickets) {

    visited = vector<bool>(tickets.size(), false);
    sort(tickets.begin(), tickets.end());

    bool t = dfs("ICN", tickets, 0);
    return answer;
}

int main()
{
   vector<string> temp = solution({ {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} });
}