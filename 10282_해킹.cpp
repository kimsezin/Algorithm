#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string data;
    char jumin1[20] = { 0, };
    char jumin2[20] = { 0, };
    char year[5] = { 0, }, month[3] = { 0, }, day[3] = { 0, };

    cout << "�ֹι�ȣ�� �Է��ϼ���:";
    getline(cin, data);
    cout << "-";
    cin >> jumin2;





    if (jumin2[0] == '1' || jumin2[0] == '2')
        strcpy_s(year, _countof(year), "19");
    else
        strcpy_s(year, _countof(year), "20");

    strncat_s(year, _countof(year), jumin1, 2);
    strncpy_s(month, _countof(month), jumin1 + 2, 2);
    strncpy_s(day, _countof(day), jumin1 + 4, 2);

    cout << "�� ������" << year << "��" << month << "��" << day << "�� �Դϴ�" << endl;


    return 0;
}