#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int N;


int main()
{
	cin >> N;
	vector<pair<pair<int, int>, pair<int, string>>> info(N);
	for (int i = 0; i < N; i++)
	{
		cin >> info[i].second.second >> info[i].second.first >>
			info[i].first.second >> info[i].first.first;
	}
	sort(info.begin(), info.end());
	cout << (*(info.end() - 1)).second.second << endl << (*(info.begin())).second.second;
	return 0;
}