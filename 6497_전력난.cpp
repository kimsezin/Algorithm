#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,pair<int, int>>> way;
int M, N;
int X, Y, Z;
int total = 0;
int parent[200010];
int result = 0;
int Find_parent(int _node)
{
	if (_node == parent[_node])
	{
		return _node;
	}
	else
		return parent[_node] = Find_parent(parent[_node]);
}



bool SameParent(int node_1, int node_2)
{
	node_1 = Find_parent(node_1);
	node_2 = Find_parent(node_2);
	if (node_1 == node_2)
	{
		return true;
	}
	else
		return false;
}
void Union(int node_1, int node_2)
{
	node_1 = Find_parent(node_1);
	node_2 = Find_parent(node_2);
	parent[node_2] = node_1;
}
void solve()
{
	sort(way.begin(), way.end());
	for (int i = 0; i < way.size(); i++)
	{
		int node_1 = way[i].second.first;
		int node_2 = way[i].second.second;
		int cost = way[i].first;

		if (SameParent(node_1, node_2) == false)
		{
			Union(node_1, node_2);
			result = result + cost;
		}
	}
	cout << total - result << endl;
}
int main()
{
	while (1)
	{
		cin >> M >> N;
		total = 0;
		result = 0;
		way.clear();
		if (M == 0 and N == 0)
		{	
			return 0;
		}
		for (int i = 0; i < N; i++)
		{
			parent[i] = i;
			cin >> X >> Y >> Z;
			way.push_back({ Z ,{ X,Y } });
			total = total + Z;
		}
		solve();
	}

	

	return 0;
}