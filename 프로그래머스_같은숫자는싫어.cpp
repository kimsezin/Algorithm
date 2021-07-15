#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	return arr;
}

int main()
{
	vector<int> arr = { 4,4,4,3,3 };
	solution(arr);
}