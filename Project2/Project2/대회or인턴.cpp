#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int cnt = 0;
	int res = 0;
	for (int i = 0; i <= k; i++)
	{
		int a = n - i;
		int b = m - (k - i);
		res = max(res, min(a / 2, b));
	}
	cout << res << endl;
}
