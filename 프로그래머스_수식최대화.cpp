#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> price;
vector<char> operators;
long long cal(long long a, long long b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else
    {
        return a * b;
    }
}
long long solution(string expression) {
    long long answer = 0;
    int temp = 0;
    
    vector<char> oper_list = { '*','-','+' };
    string num="";
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] > '0' && expression[i] < '9')
        {
            operators.push_back(expression[i]);
            price.push_back(stoi(num));
            num = "";
        }
        else
        {
            num += expression[i];
        }
    }
    price.push_back(stoi(num));
    do {
        vector<char> oper = operators;
        vector<long long> pr = price;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < oper.size(); i++)
            {
                if (oper[j] == oper_list[i])
                {
                    pr[j] = cal(pr[j], pr[j + 1], oper[j]);
                }
            }
        }

    } while (next_permutation(oper_list.begin(), oper_list.end()));
    {

    }
    return answer;
}

int main()
{
    solution("100-200*300-500+20");
}