#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	//1단계 소문자로 치환
	//2단계 알파벳, 숫자, -, _, . 아닌거 제거
	for (int i = 0; i < new_id.size(); i++)
	{
		new_id[i] = tolower(new_id[i]); // 소문자로 치환

		if (!(new_id[i] >= 'a' && new_id[i] <= 'z')) // 알파벳 아닌거
		{
			if (!(new_id[i] >= '0' && new_id[i] <= '9'))// 숫자 아닌거
			{
				if (!(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) //빼기, 밑줄, 마침표 아닌거
				{
					new_id.erase(i,1);
					i--;
				}
			}
		}
	}

	//3단계 연속된 점(.) 하나로 치환
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
	
	//4단계 처음과 끝에 있는 점 (.) 제거
	if (new_id[0] == '.')
	{
		new_id.erase(0, 1);
	}
	if (new_id[new_id.size() - 1] == '.')
	{
		new_id.erase(new_id.size() - 1, 1);
	}
	
	//5단계 빈 문자열일 경우 "a"로 바꾸기
	if (new_id == "")
	{
		new_id += "a";
	}

	//6단계 문자열길이가 16이상일 경우 16부터 끝까지 다 삭제 후 끝에 점(.)이면 삭제
	if (new_id.size() > 15)
	{
		int erase_cnt = new_id.size() - 15;
		new_id.erase(15, erase_cnt);
		while (new_id[new_id.size() - 1] == '.')
		{
			new_id.erase(new_id.size() - 1, 1);
		}
	}
	
	//7단계 문자열 길이가 2 이하일 경우 3까지 끝 문자 추가
	if (new_id.size() <= 2)
	{
		while (!(new_id.size() == 3))
		{
			new_id += new_id[new_id.size() - 1];
		}
	}
	
	return new_id;
}
