#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(), scoville.end());
    while (pq.size() > 1 && pq.top() < K)
    {
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();

        pq.push(temp1 + temp2 * 2);
        answer++;
    }
    if (answer == 0)
    {
        return -1;
    }
    return answer;
}

int main()
{
    solution({ 1,2,3,9,10,12 }, 7);

}
