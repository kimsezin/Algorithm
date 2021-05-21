#include<iostream>
#include<queue>
#include<cstring>

using namespace std;


int T;
int A, B;
bool Visit[10000];
string solve()
{
    memset(Visit, false, sizeof(Visit));
    queue<pair<int, string>> Q;
    Q.push(make_pair(A, ""));
    Visit[A] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        string s = Q.front().second;
        Q.pop();

        if (x == B)
        {
            return s;
        }

        int nx = x * 2;
        if (nx > 9999) nx = nx % 10000;
        if (Visit[nx] == false)
        {
            Visit[nx] = true;
            Q.push(make_pair(nx, s + "D"));
        }

        nx = x - 1;
        if (nx < 0) nx = 9999;
        if (Visit[nx] == false)
        {
            Visit[nx] = true;
            Q.push(make_pair(nx, s + "S"));
        }

        nx = (x % 1000) * 10 + (x / 1000);
        if (Visit[nx] == false)
        {
            Visit[nx] = true;
            Q.push(make_pair(nx, s + "L"));
        }

        nx = (x % 10) * 1000 + (x / 10);
        if (Visit[nx] == false)
        {
            Visit[nx] = true;
            Q.push(make_pair(nx, s + "R"));
        }
    }

}
int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        string result = solve();
        cout << result << endl;
    }

    return 0;
}