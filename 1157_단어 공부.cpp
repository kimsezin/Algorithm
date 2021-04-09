#include<iostream>

using namespace std;
string str;
int alpha[26];
int idx = 0;
int main()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= 'Z')
		{
			alpha[str[i] - 'A']++;
		}
		else if (str[i] <= 'z')
		{
			alpha[str[i] - 'a']++;
		}
	}

	int max_value = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max_value < alpha[i])
		{
			max_value = alpha[i];
			idx = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (max_value == alpha[i] and i != idx)
		{
			cout << "?";
			return 0;
		}
	}
	cout << char('A'+idx);
	return 0;
}