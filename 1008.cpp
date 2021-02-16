#include<iostream>

using namespace std;

int main()
{
	double a, b = 0;
	cin >> a >> b;

	if (a > 0 or b < 10)
	{
		std::cout << fixed;
		std::cout.precision(10);

		cout << a / b;
	}
	else
		return 0;
}