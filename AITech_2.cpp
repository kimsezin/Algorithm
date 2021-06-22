#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int main()
{
	int cnt = 0;
	bool bonus_check = false;
	int lotto[6];
	int user_lotto[6];
	int bonus;
	int temp;
	for (int i = 0; i < 6; i++)
	{
		cin >> temp;
		lotto[i] = temp;
	}
	cin >> bonus;
	for (int i = 0; i < 6; i++)
	{
		cin >> temp;
		user_lotto[i] = temp;
	}


	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (bonus == user_lotto[i])
			{
				bonus_check = true;
			}
			if (lotto[i] == user_lotto[j])
			{
				cnt++;
				break;
			}
			
		}
	}

	switch (cnt)
	{
	case 6:cout << 1 << endl;
		break;
	case 5:if (bonus_check == true)
		cout << 2 << endl;
		  else
		cout << 3 << endl;
		break;
	case 4: cout << 4 << endl;
		break;
	case 3: cout << 5 << endl;
		break;
	}
	return 0;
}