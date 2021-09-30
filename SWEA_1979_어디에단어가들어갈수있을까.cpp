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

using namespace std;

int N, K;
int map[15][15] = { 0, };
int answer = 0;
void check_x()
{    
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cnt = 0;
        int flag = false;
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 0)
            {
                if (flag == true)
                {
                    flag = false;
                    cnt = 0;
                }
            }
            if (map[i][j] == 1)
            {
                flag = true;
                cnt++;
                if (cnt == K)
                {
                    if (j + 1 >= N)
                    {
                        answer++;
                    }
                    else if (map[i][j + 1] == 0)
                        answer++;
                }
            }
        }
        
    }
}

void check_y()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cnt = 0;
        bool flag = false;
        for (int j = 0; j < N; j++)
        {
            if (map[j][i] == 0)
            {
                if (flag == true)
                {
                    cnt = 0;
                    flag = false;
                }
            }
            if (map[j][i] == 1)
            {
                flag = true;
                cnt++;
                if (cnt == K)
                {
                    if (j + 1 >= N)
                    {
                        answer++;
                    }
                    else if (map[j+1][i] == 0)
                        answer++;
                }
            }
        }

    }
}
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


    for (test_case = 1; test_case <= T; ++test_case)
    {
    
        cin >> N >> K;
        answer = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int temp;
                cin >> temp;
                map[i][j] = temp;
            }
        }
        
        
        check_x();
        check_y();
        cout << '#' << test_case << ' ' << answer << endl;


    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}