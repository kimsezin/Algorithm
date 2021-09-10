#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int N, M, V;
#define size 1001

vector<vector<int>> input(size, vector<int>(size, 0));

stack<int> s;
queue<int> q;
vector<bool> dfs_visited(size,false);
vector<bool> bfs_visited(size,false);


void doDFS(int V)
{	
	dfs_visited[V] = true;
	cout << V << " ";

	for (int i = 1; i <= N; i++) {
		if (input[V][i] == 1 && dfs_visited[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
			doDFS(i);
		}
	}
}

void doBFS(int v)
{
	q.push(v);
	bfs_visited[v] = true;
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int w = 1; w <= N; w++) {
			if (input[v][w] == 1 && bfs_visited[w] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
				q.push(w);
				bfs_visited[w] = true;
				cout << w << " ";
			}
		}
	}
}
int main()
{
	cin >> N >> M >> V;
	
	for (int i = 1; i <= M; i++)
	{
		int start, end;
		cin >> start >> end;
		input[start][end] = 1;
		input[end][start] = 1;
	}

	doDFS(V);
	cout << endl;
	doBFS(V);

	return 0;
}