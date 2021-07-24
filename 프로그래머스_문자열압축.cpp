#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int length = s.size();
	int answer = length;

	for (int i = 1; i <= length / 2; i++)
	{
		string result = "";

		string temp = s.substr(0, i);
		int cnt = 1;
		for (int j = i; j <= length; j += i)
		{
			if (temp == s.substr(j, i))
			{
				cnt++;
			}
			else
			{
				if (cnt == 1)
				{
					result += temp;
				}
				else
				{
					result += (to_string(cnt) + temp);
				}
				temp = s.substr(j, i);
				cnt = 1;
			}
		}
		if (length % i != 0)
		{
			result += s.substr((length / i) * i);
		}

		if (answer > result.size())
		{
			answer = result.size();
		}
	}
	return answer;
}

int main()
{
	string s = "aabcbc";
	solution(s);
}