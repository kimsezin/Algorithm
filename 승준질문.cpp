#include<iostream>
using namespace std;

int main()
{
    char jumin[30] = { 0, };
    char year[10] = { 0, };
    char month[5] = { 0, };
    char day[5] = { 0, };
    cout << "������� �ֹε�Ϲ�ȣ�� �Է��ϼ���(�߰���ȣ-�� �������ּ���):";
    cin >> jumin;

    if (jumin[7] == 1 || jumin[7] == 2)
    {
        strcpy_s<10>(year, "19");
    }
    else
    {
        strcpy_s<10>(year, "20");
    }

    strncat_s(year, 10, jumin, 2);
    strncpy_s(month, 5, jumin + 2, 2);
    strncpy_s(day, 5, jumin + 4, 2);

    cout << "������" << endl;
    cout << "�Է� �ֹε�� ��ȣ:" << jumin << endl;
    cout << "����� " << year << "�� " << month << "�� " << day << "�Ͽ� �¾�̽��ϴ�." << endl;
    switch (jumin[7])
    {
    case('1'):
    {
        cout << "����� ������ �����Դϴ�." << endl;
        break;
    }
    case('3'):
    {
        cout << "����� ������ �����Դϴ�." << endl;
        break;
    }
    case('2'):
    {
        cout << "����� ������ �����Դϴ�." << endl;
        break;
    }
    case('4'):
    {
        cout << "����� ������ �����Դϴ�." << endl;
        break;
    }
    default:
        break;
    }
    return 0;
}