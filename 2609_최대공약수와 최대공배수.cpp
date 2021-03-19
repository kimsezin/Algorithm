#include<iostream>

using namespace std;

int gcc(int _n1, int _n2)
{
	int r;
	while (_n2 != 0)
	{
		r = _n1 % _n2;
		_n1 = _n2;
		_n2 = r;
	}
	return _n1;
}
int main()
{
	int n1, n2;
	cin >> n1 >> n2;

	int a, b;
	a = gcc(n1, n2);
	b = (n1 * n2) / a;
	cout << a << endl << b;
	return 0;
}