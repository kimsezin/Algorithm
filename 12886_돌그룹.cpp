#include<iostream>
#include<queue>
#include<iterator>
#include<algorithm>
using namespace std;
bool check[1000][1000];
queue<pair<int, int>> numbers;
int A, B, C, D;
void solve()
{
	numbers.push({ A,B });
	check[A][B] = true;
	while (!numbers.empty())
	{
		int x = numbers.front().first;
		int y = numbers.front().second;
		numbers.pop();

		int z = D - x - y;

		if (x == y and y == z)
		{
			cout << 1;
			return;
		}
		int nx[3] = { x,x,y };
		int ny[3] = { y,z,z };
		for (int i = 0; i < 3; i++)
		{
			int a = nx[i];
			int b = ny[i];
			if (a < b)
			{
				b = b - a;
				a = a + a;
			}
			else if (a > b)
			{
				a = a - b;
				b = b + b;
			}
			else
			{
				continue;
			}
			int c = D - a - b;
			int X = min(min(a, b), c);
			int Y = max(max(a, b), c);
			if (!check[X][Y])
			{
				numbers.push({ X,Y });
				check[X][Y] = true;
			}
		}
	}
	cout << 0;
}
int main()
{
	cin >> A >> B >> C;
	D = A + B + C;
	if (D % 3 != 0)
	{
		cout << 0;
		return 0;
	}
	solve();
	return 0;
}