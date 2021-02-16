#include <iostream>

using namespace std;

double recursive(int num)
{
    if (num == 0)
        return 1;
    else
    {
        return num * recursive(num - 1);
    }
}

unsigned long long result[30] = { 0, };
int case_num(int west, int east)
{
    double sum = recursive(east) / (recursive(west) * recursive(east - west));
    int r_sum = round(sum);
    for (int k = 0; k < 31; k++)
    {
        result[k] = r_sum;
    }
    return 1;
}


int main()
{
    int n;
    cin >> n;

    int west, east;
    // arr[31] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> west;
        cin >> east;

        int w= case_num(west, east);
    }

    for (int k = 0; k < 30; k++)
    {
        if (result[k] == 0)
        {
            return 0;
        }
        cout << result[k];
    }

}