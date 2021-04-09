#include<iostream>
#include<string>

using namespace std;
string str;

void solve()
{
	while (1)
	{
		getline(cin, str);
		if (str == "END")
		{
			return;
		}
		else
		{
			for (int i = str.size()-1; i > -1; i--)
			{
				cout << str[i];
			}
			cout << endl;
		}
	}
}
int main()
{
	
	solve();
	

	return 0;
}