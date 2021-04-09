#include<iostream>
#include<string>

using namespace std;

string str1, str2;
int T;
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str1;
		cin >> str2;
		cout << "Distances:";
		for (int j = 0; j < str1.size(); j++)
		{
			if (str1[j] <= str2[j])
				cout << " " << str2[j] - str1[j];
			else if (str1[j] > str2[j])
			{
				cout << " " << 'Z' - str1[j] + str2[j] -'A'+1 ;
			}
		}
		cout << endl;
	}
}