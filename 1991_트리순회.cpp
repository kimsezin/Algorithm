#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

struct node
{
	char data;
	char left;
	char right;
};

node Tree[27];

int N;
void first(char data)
{
	if (data == '.')
	{
		return;
	}
	else
	{
		cout << Tree[data - 'A'].data;
		first(Tree[data - 'A'].left);
		first(Tree[data - 'A'].right);
	}
}
void second(char data)
{
	if (data == '.')
	{
		return;
	}
	else
	{
		second(Tree[data - 'A'].left);
		cout << Tree[data - 'A'].data;
		second(Tree[data - 'A'].right);
	}
}
void third(char data)
{
	if (data == '.')
	{
		return;
	}
	else
	{
		third(Tree[data - 'A'].left);
		third(Tree[data - 'A'].right);
		cout << Tree[data - 'A'].data;
	}
}
int main()
{
	scanf("%d", &N);
	char data, data_l, data_r;
	for (int i = 0; i < N; i++)
	{
		cin >> data >> data_l >> data_r;
		Tree[data - 'A'].data = data;
		Tree[data - 'A'].left = data_l;
		Tree[data - 'A'].right = data_r;
	}

	first('A');
	cout << endl;
	second('A');
	cout << endl;
	third('A');
	
}