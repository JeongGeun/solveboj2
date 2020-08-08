#include<iostream>
#include<vector>
using namespace std;

int dp[1001];

int main()
{
	int s = 1;
	vector<int>v;
	while (1)
	{
		int num = s * (s + 1) / 2;
		if (num > 1000) break;
		v.push_back(num);
		s++;
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			for (int a = 0; a < v.size(); a++)
			{
				if (v[i] + v[j] + v[a] <= 1000)
				{
					dp[v[i] + v[j] + v[a]] = 1;
				}
			}
		}
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		cout << dp[k] << endl;
	}



}