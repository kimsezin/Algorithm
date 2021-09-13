#include <vector>
#include <algorithm>
using namespace std;


/*
 * Complete the 'countMoves' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY numbers as parameter.
 */

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))    //SWAP함수 설정
int partition(vector<int> list, int left, int right)
{
    int pivot = list[left], tmp, low = left, high = right + 1;

    do {
        do
            low++;
        while (low <= right && list[low] < pivot);

        do
            high--;
        while (high >= left && list[high] > pivot);
        if (low < high) SWAP(list[low], list[high], tmp);
    } while (low < high);

    SWAP(list[left], list[high], tmp);
    return high;
}
void quick_sort(vector<int> list, int left, int right)
{
    if (left < right)
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}
long countMoves(vector<int> numbers) {
    long cnt = 0;
    while (1)
    {
        quick_sort(numbers, 0, numbers.size());
        if (numbers[0] == numbers[numbers.size() - 1])
        {
            return cnt;
        }
        
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            numbers[i]++;
        }
        cnt++;
    }
}

int main()
{

    countMoves({ 3,4,6,6,3 });
        return 0;
}
