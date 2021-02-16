#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int arr[30][30];

// dp 이용
//1번 -> 큰 문제를 작은 문제로 나눌수 있어야함
//2번 -> 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일
// 조합 -> nCr = n-1Cr + n-1Cr-1

int case_num(int east, int west)
{
=	if (east == west || west == 0)
		return 1;
	if (arr[east][west]) //계산된 결과 저장
		return arr[east][west];
	return arr[east][west] = case_num(east - 1, west) + case_num(east - 1, west - 1);
}

int main()
{
	int test_case;
	int west, east;

	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d", &west);
		scanf("%d", &east);
		printf("%d\n", case_num(east, west));
	}



}