#include<iostream>

using namespace std;

int Tc, N, start_idx, end_idx;
bool order;

int Arr[100001]; //숫자만 뽑아내서 저장할 배열
char command[100001]; //명령어만 따로 저장할 배열
char input_arr[400004]; //처음에 입력받을 배열

void Initialize()
{
	for (int i = 0; i < 100001; i++)
	{
		Arr[i] = 0;
		command[i] = '\0'; //\0은 Null을 의미 숫자 0하고 구분하기위함
	}
	for (int i = 0; i < 100001; i++)
	{
		input_arr[i] = '\0';
	}
	start_idx = 0;
	end_idx = 0;
	order = true;
}

int My_Strlen_ch(char* A)
{
	int i = 0;
	while (A[i] != 0)
	{
		i++;
	}
	return i;
}
int My_Strlen_int(int* A)
{
	int i = 0;
	while (A[i] != 0)
	{
		i++;
	}
	return i;
}
void Input()
{
	cin >> command;
	cin >> N;
	cin >> input_arr;
	int len = My_Strlen_ch(input_arr);
	int Idx = 0;

	for (int i = 0; i < len; i++)
	{
		if (input_arr[i] != '[' && input_arr[i] != ']' && input_arr[i] != ',')
		{
			int j = i;
			int x = 0;
			while (input_arr[i] != '[' && input_arr[i] != ']' && input_arr[i] != ',')
			{
				x = x + (input_arr[j] - '0');
				x = x * 10;
				j++;
				i++;
			}
			x = x / 10;
			Arr[Idx++] = x; // 숫자만 추출한 배열에 저장
		}
	}
	end_idx = Idx - 1;
}
void solution()
{
	bool Flag = true;
	int len = My_Strlen_ch(command);
	int size = My_Strlen_int(Arr);

	for (int i = 0; i < len; i++)
	{
		if (command[i] == 'R')
		{
			if (order == true)
			{
				order = false;
			}
			else
			{
				order = true;
			}
		}
		else
		{
			if (size == 0)
			{
				Flag = false;
				cout << "error" << endl;
			}

			if (order == true)
			{
				start_idx++;
				size--;
			}
			else
			{
				end_idx--;
				size--;
			}
		}
	}
	if (Flag == true)
	{
		cout << "[";
		if (order == true)
		{
			for (int i = start_idx; i <= end_idx; i++)
			{
				if (i != end_idx)
				{
					cout << Arr[i] << ",";
				}
				else //첫, 마지막 숫자는 , 없애기위해
				{
					cout << Arr[i];
				}
			}
		}
		else
		{
			for (int i = end_idx; i >= start_idx; i--)
			{
				if (i != start_idx)
				{
					cout << Arr[i] << ",";
				}
				else
				{
					cout << Arr[i];
				}
			}
		}
		cout << "]" << endl;
	}
}
void solve()
{
	for (int i = 0; i < Tc; i++)
	{
		Initialize();
		Input();
		solution();
	}
}

int main()
{
	
	cin.tie(0);
	cout.tie(0);
	cin >> Tc;
	solve();
}