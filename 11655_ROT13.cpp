#include<iostream>
#include<string>
using namespace std;

int main()
{
	string data;
	getline(cin, data);

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == ' ')
			continue;
		if (data[i] > 'z' - 13)
		{
			data[i] = (data[i]-('z'-13)) + 'a' -1;
			continue;
		}

		else if (data[i] > 'Z'-13 and data[i] < 'a')
		{
			data[i] = (data[i] - ('Z'-13)) + 'A'-1;
		}
		else if (data[i] <= '9')
		{
			continue;
		}
		else
		{
			data[i] = data[i] + 13;
		}
		
		
	}
	cout << data;
	return 0;
}