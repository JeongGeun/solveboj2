#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long int n, k;
	cin >> n >> k;
	
	long long int left = 1;
	long long int right = n*n;
	long long int res = 0;
	while (left <= right)
	{
		long long int cnt = 0;
		long long int mid = (left + right) / 2;
		for (int i = 1; i <= n; i++)
			cnt += min(n, mid / i);
		if (cnt < k)
		{
			left = mid + 1;
		}
		else
		{
			res = mid;
			right = mid - 1;
		}
	}
	cout << res << endl;
}