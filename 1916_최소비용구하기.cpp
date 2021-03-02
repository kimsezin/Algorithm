#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;


vector<pair<int, int>> city[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[1001];
bool visited[1001] = { false, };


void doDijkstra(int _start)
{
	dist[_start] = 0;

	pq.push({ 0, _start });
	while (!pq.empty())
	{
		int _dest = pq.top().second;
		pq.pop();

		if (visited[_dest] == false)
		{
			visited[_dest] = true;
			for (int i = 0; i < city[_dest].size(); i++)
			{
				int _next = city[_dest][i].first;
				if (dist[_next] > dist[_dest] + city[_dest][i].second)
				{
					dist[_next] = dist[_dest] + city[_dest][i].second;
					pq.push({ dist[_next], _next });
				}
			}
		}
		
	}
}
int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		city[x].push_back({ y,cost });
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = 1000000000;
	}
	doDijkstra(start);

	cout << dist[end];
	return 0;
}