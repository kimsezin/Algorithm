#include<iostream>
using namespace std;

int main()
{
    char jumin[30] = { 0, };
    char year[10] = { 0, };
    char month[5] = { 0, };
    char day[5] = { 0, };
    cout << "사용자의 주민등록번호를 입력하세요(중간기호-를 포함해주세요):";
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

    cout << "실행결과" << endl;
    cout << "입력 주민등록 번호:" << jumin << endl;
    cout << "당신은 " << year << "년 " << month << "월 " << day << "일에 태어나셨습니다." << endl;
    switch (jumin[7])
    {
    case('1'):
    {
        cout << "당신의 성별은 남자입니다." << endl;
        break;
    }
    case('3'):
    {
        cout << "당신의 성별은 남자입니다." << endl;
        break;
    }
    case('2'):
    {
        cout << "당신의 성별은 여자입니다." << endl;
        break;
    }
    case('4'):
    {
        cout << "당신의 성별은 여자입니다." << endl;
        break;
    }
    default:
        break;
    }
    return 0;
}