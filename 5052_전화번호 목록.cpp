#include<iostream>

using namespace std;


struct TRIE
{
	bool finish;
	TRIE* node[10001];

	void insert(char* s)
	{
		if (*s == NULL)
		{
			finish = true;
			return;
		}

		int cur = *s - '0';
		if (node[cur] == NULL)
		{
			node[cur] = new TRIE;
		}
		node[cur]->insert(s + 1);
		
	}

	bool call(char* s)
	{
		if (*s == NULL)
		{
			return true;
		}
		if (finish == true)
		{
			return false;
		}

		int cur = *s - '0';
		node[cur] -> call(s - 1);
	}
};

TRIE* root = 0;
int t;
int n;
char phone[10000][10];

void solve()
{
	for (int i = 0; i < n; i++)
	{

	}
	for (int i = 0; i < n; i++)
	{
		root->insert(phone[i]);
	}
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (flag == true)
		{
			flag = root->call(phone[i]);
		}
		if(flag == false)
		{
			break;
		}
	}
	if (flag == true)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		root = 0;
	
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> phone[j];
		}
		for(int i=0;i<)
		solve();
	}

	return 0;
}