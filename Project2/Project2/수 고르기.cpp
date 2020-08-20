#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int n;
long long int m;
long long int arr[100001];

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int low = 0;
	int hi = 0;
	long long int res = -1;
	while (low < n)
	{
		if (arr[hi] - arr[low] >= m)
		{
			if (res == -1)res = arr[hi] - arr[low];
			else
			{
				res = min(res, arr[hi] - arr[low]);
			}
			low++;
		}
		else
		{
			if (hi < n-1)
				hi++;
			else low++;
		}
	}
	cout << res << endl;
}