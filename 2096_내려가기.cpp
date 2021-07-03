#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int maxdp[3];
int mindp[3];
int input[3];
int temp[3];
int N;
int main()
{
	cin >> N;
	cin >> maxdp[0] >> maxdp[1] >> maxdp[2];
	memcpy(mindp, maxdp, sizeof(maxdp));
	for (int i = 0; i < N-1; i++)
	{
		cin >> input[0] >> input[1] >> input[2];
		memcpy(temp, maxdp, sizeof(maxdp));
		maxdp[0] = max(temp[0], temp[1]) + input[0];
		maxdp[1] = max(max(temp[0], temp[1]), temp[2]) + input[1];
		maxdp[2] = max(temp[1], temp[2]) + input[2];

		memcpy(temp, mindp, sizeof(mindp));
		mindp[0] = min(temp[0], temp[1]) + input[0];
		mindp[1] = min(min(temp[0], temp[1]), temp[2]) + input[1];
		mindp[2] = min(temp[1], temp[2]) + input[2];
	}
	cout << max(max(maxdp[0], maxdp[1]), maxdp[2]) << " " << min(min(mindp[0], mindp[1]), mindp[2]) << endl;
	return 0;
}