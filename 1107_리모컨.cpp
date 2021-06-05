#include<iostream>
#include<cmath>

using namespace std;

bool break_down[10];

int target;
int N;
int check(int n)
{
	if (n == 0)
	{
		if (break_down[0])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	int len = 0;
	while (n > 0)
	{
		if (break_down[n % 10])
		{
			return 0;
		}
		n = n / 10;
		len += 1;
	}
	return len;
}
int main()
{
	cin.tie(0);
	cout.tie(0);


	cin >> target >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		break_down[num] = true;
	}

	int result = abs(target - 100); //�������� 100�ε� 0���� �ٲ㼭 ����ϱ� ���ϰ�
	for (int i = 0; i < 1000000; i++)
	{
		int len = check(i);
		if (len > 0)
		{
			int press = abs(i - target);
			if (result > press + len)
			{
				result = press + len;
			}
		}
	}
	cout << result << endl;
	return 0;
}
