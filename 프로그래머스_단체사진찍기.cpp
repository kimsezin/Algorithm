#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool select[8];
char ItoC[8] = { 'A','C','F','J','M','N','R','T' };

void DFS(int cnt, char Arr[], vector<string> data)
{
    if (cnt == 8)
    {
        for (int i = 0; i < data.size(); i++)
        {
            char N1 = data[i][0];
            char N2 = data[i][2];
            char cond = data[i][3];
            int Dist = data[i][4] - '0';
            Dist++;

            int idx1, idx2;
            idx1 = idx2 = -1;
            for (int j = 0; j < 8; j++)
            {
                if (Arr[j] == N1) idx1 = j;
                if (Arr[j] == N2) idx2 = j;
                if (idx1 != -1 && idx2 != -1)
                {
                    break;
                }
            }

            if (cond == '=' && abs(idx1 - idx2) != Dist)return;
            if (cond == '<' && abs(idx1 - idx2) >= Dist)return;
            if (cond == '>' && abs(idx1 - idx2) <= Dist)return;
        }
        answer++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (select[i] == true)
        {
            continue;
        }
        select[i] = true;
        Arr[cnt] = ItoC[i];
        DFS(cnt + 1, Arr, data);
        select[i] = false;
    }
}
int solution(int n, vector<string> data) {
    char Arr[8] = { NULL, };
    DFS(0, Arr, data);
    return answer;
}

int main()
{
    solution(2, { "N~F=0", "R~T>2" });
}