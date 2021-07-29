#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> result;
    stack<int> s;
    for (int i = 0; i < moves.size(); i++)
    {
        int temp = moves[i] - 1;
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[j][temp] != 0)
            {
                if (!s.empty() && s.top() == board[j][temp])
                {
                    s.pop();
                    answer += 2;
                }
                else
                {
                    s.push(board[j][temp]);
                }
                board[j][temp] = 0;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}}, {1, 5, 3, 5, 1, 2, 1, 4});
}