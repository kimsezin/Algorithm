#include<vector>
#include<iostream>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;
vector<string> picture;
vector<vector<int>> visited;

int _size=0;

void doDFS(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = x + dy[i];

        if (nx >= 0 && ny >= 0 && nx < visited.size() && ny < visited[0].size())
        {
            if (picture[nx][ny] == picture[x][y] && visited[nx][ny] == 0)
            {
                doDFS(nx, ny);
            }
            else
            {
                cnt++;
            }
        }
    }
}
int strokesRequired(vector<string> picture) {
    doDFS(0, 0);
    return cnt;
}

int main()
{
    int h;
    cin >> h;
    vector<string> picture(h);

    for (int i = 0; i < h; i++) {
        string picture_item;
        cin >> picture_item;

        picture[i] = picture_item;
    }
    visited = vector<vector<int>>(picture.size(), vector<int>(picture[0].size(), 0));
    int result = strokesRequired(picture);

    return 0;
}