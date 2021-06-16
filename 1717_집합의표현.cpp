#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int a, b;
bool check;
int group[1000000];

int find(int _x)
{
	if (_x == group[_x])
	{
		return _x;
	}
	return group[_x] = find(group[_x]);
}
void _union()
{
	int pa = find(a);
	int pb = find(b);

	if (pa > pb)
	{

	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		group[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> check >> a >> b;
		if (check == 0)
		{
			_union();
		}
		else
		{
			if (find(a) == find(b))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}