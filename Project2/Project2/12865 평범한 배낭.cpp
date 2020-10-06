#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> P;
int dp[101][100001];
vector<P> v;

/***
	배낭 문제 기초(DP)
	점화식 하나만 기억하자
	i : 배낭의 집어넣을 수 있는 물건들의 index
	j : 내가 들 수 있는 한계 (1<= <=k)
	dp[i][j]=dp[i-1][j]
	dp[i][j]= max(dp[i][j],dp[i-1][j-w]+v)
***/

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - v[i - 1].first >= 0)
			{
				dp[i][j] = max(dp[i - 1][j],dp[i-1][j-v[i-1].first]+v[i-1].second );
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][k];
}