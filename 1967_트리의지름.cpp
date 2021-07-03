#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<pair<int, int>> tree[10001];
int res;
int end_point;
int N;
bool visited[10001];
void dfs(int point, int length)
{
	if (visited[point] == true)
	{
		return;
	}

	visited[point] = true;
	if (res < length)
	{
		res = length;
		end_point = point;
	}
	for (int i = 0; i < tree[point].size(); i++)
	{
		dfs(tree[point][i].first, tree[point][i].second + length);
	}
}
int main()
{
	int parent, child, length;
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		cin >> parent >> child >> length;
		tree[parent].push_back({ child,length });
		tree[child].push_back({ parent,length });
	}

	dfs(1, 0);
	res = 0;
	memset(visited, 0, sizeof(visited));

	dfs(end_point, 0);
	cout << res << endl;

	return 0;
}