#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
//using namespace std;
//
//int N;
//vector<int> cost;
//vector<int> copy_cost;
//unsigned long long total = 0;
//int temp = 1;
//int result;
//int index = 0;
//vector<int>::iterator it;
//int solve()
//{
//	for (unsigned long long i = 1; i <= total; i++)
//	{
//		temp = i;
//		cost = copy_cost;
//		while (temp > 0)
//		{
//			it = find(cost.begin(), cost.end(), temp);
//			if (it != cost.end())
//			{
//				break;
//			}
//			else
//			{
//				for (auto e = cost.begin(); e != cost.end(); e++)
//				{
//					if (cost.size()==1)
//					{
//						if (*cost.begin() > temp)
//						{
//							return i;
//						}
//					}
//					if (*e > temp)
//					{
//						temp = temp - *(e-1);
//						cost.erase(e-1);
//						break;
//					}
//				}
//				/*temp = temp - *cost.begin();
//				cost.erase(cost.begin());*/
//			}
//			
//		}
//		result = i;
//	}
//	return result;
//}
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int t;
//		cin >> t;
//		total += t;
//		cost.push_back(t);
//	}
//	
//	sort(cost.begin(),cost.end());
//	copy_cost = cost;
//	int ans = solve();
//	cout << ans;
//	return 0;
//}


using namespace std;

int main() {

    int n;
    vector<int> v;
    cin >> n;
    int possible = 1;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (possible >= v[i]) {
            possible += v[i];
        }
        else break;
    }
    cout << possible << '\n';
}