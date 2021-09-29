/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<map>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
       ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
       //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
       freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
       ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
       freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
       ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
    */
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
    */
    map<int, string> credit;
    credit[0] = "A+";
    credit[1] = "A0";
    credit[2] = "A-";
    credit[3] = "B+";
    credit[4] = "B0";
    credit[5] = "B-";
    credit[6] = "C+";
    credit[7] = "C0";
    credit[8] = "C-";
    credit[9] = "D0";
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, K;
        cin >> N >> K;
        vector<double> score;
        map<int, double> student_score;
        double K_credit;
        for (int i = 0; i < N; i++)
        {
            double midterm, finalterm, homework;
            cin >> midterm >> finalterm >> homework;
            double sum = (midterm * 0.35) + (finalterm * 0.45) + (homework * 0.2);
            score.push_back(sum);
            student_score[i] = sum;

            if (i + 1 == K)
            {
                K_credit = sum;
            }
        }
        sort(score.begin(), score.end(), greater<double>());
        int idx;

        for (int i = 0; i < score.size(); i++)
        {
            if (score[i] == K_credit)
            {
                idx = i;
                break;
            }
        }

        cout << '#' << test_case << ' ' << credit[idx/(N/10)] << endl;
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}