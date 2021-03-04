#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<iostream>
#include<iterator>

using namespace std;

int main()
{
	set<int> myset;

	myset.insert(5);
	myset.insert(3);
	myset.insert(1);
	myset.insert(2);
	myset.insert(4);

	//1이 있으면 그 위치에대한 iterator
	//없으면 myset.end()
	auto pos = myset.find(6);

	if (pos == myset.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Found" << endl;
	}

	pair<set<int>::iterator, bool> res = myset.insert(30);

	if (res.second == false)
	{
		cout << "Already Exist" << endl;
	}
	else
	{
		cout << "Insertion Success" << endl;
	}

	myset.erase(3);
	for (auto e = myset.begin(); e != myset.end(); e++)
	{
		cout << *e << " ";
	}
	cout << endl;
	return 0;
}