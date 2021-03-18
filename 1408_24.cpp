#include<iostream>

using namespace std;

int main()
{
	int h, m, s;
	int now_t;
	int start_t;
	scanf("%d:%d:%d", &h, &m, &s);
	now_t = s + m * 60 + h * 3600;
	scanf("%d:%d:%d", &h, &m, &s);
	start_t = s + m * 60 + h * 3600;

	int res;
	if (now_t < start_t)
	{
		res = start_t - now_t;
		h = res / 3600;
		res = res % 3600;
		m = res / 60;
		res = res % 60;
	}
	else
	{
		start_t = start_t + (60 * 60 * 24);
		res = start_t - now_t;
		h = res / 3600;
		res = res % 3600;
		m = res / 60;
		res = res % 60;
	}
	printf("%02d:%02d:%02d", h, m, res);

	return 0;
}