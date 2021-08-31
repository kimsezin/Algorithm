#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	//1�ܰ� �ҹ��ڷ� ġȯ
	//2�ܰ� ���ĺ�, ����, -, _, . �ƴѰ� ����
	for (int i = 0; i < new_id.size(); i++)
	{
		new_id[i] = tolower(new_id[i]); // �ҹ��ڷ� ġȯ

		if (!(new_id[i] >= 'a' && new_id[i] <= 'z')) // ���ĺ� �ƴѰ�
		{
			if (!(new_id[i] >= '0' && new_id[i] <= '9'))// ���� �ƴѰ�
			{
				if (!(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) //����, ����, ��ħǥ �ƴѰ�
				{
					new_id.erase(i,1);
					i--;
				}
			}
		}
	}

	//3�ܰ� ���ӵ� ��(.) �ϳ��� ġȯ
	for (int i = 0; i < new_id.size(); i++)
	{
		int endpoint_cnt = 1;
		if (new_id[i] == '.')
		{
			while (new_id[i + endpoint_cnt] == '.')
			{
				endpoint_cnt++;
			}
			new_id.erase(i, endpoint_cnt - 1);
		}
	}
	
	//4�ܰ� ó���� ���� �ִ� �� (.) ����
	if (new_id[0] == '.')
	{
		new_id.erase(0, 1);
	}
	if (new_id[new_id.size() - 1] == '.')
	{
		new_id.erase(new_id.size() - 1, 1);
	}
	
	//5�ܰ� �� ���ڿ��� ��� "a"�� �ٲٱ�
	if (new_id == "")
	{
		new_id += "a";
	}

	//6�ܰ� ���ڿ����̰� 16�̻��� ��� 16���� ������ �� ���� �� ���� ��(.)�̸� ����
	if (new_id.size() > 15)
	{
		int erase_cnt = new_id.size() - 15;
		new_id.erase(15, erase_cnt);
		while (new_id[new_id.size() - 1] == '.')
		{
			new_id.erase(new_id.size() - 1, 1);
		}
	}
	
	//7�ܰ� ���ڿ� ���̰� 2 ������ ��� 3���� �� ���� �߰�
	if (new_id.size() <= 2)
	{
		while (!(new_id.size() == 3))
		{
			new_id += new_id[new_id.size() - 1];
		}
	}
	
	return new_id;
}
