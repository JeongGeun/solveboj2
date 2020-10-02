#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
int dp[501][501];
struct node
{
	int x;
	int y;
};
vector<node> v;

int dist(int a ,int b)
{
	return abs(v[a].x - v[b].x) + abs(v[a].y - v[b].y);
}

int dfs(int num, int cnt)
{
	if (num == n - 1)return 0;
	int& ret = dp[num][cnt];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i <= cnt; i++)
	{
		if (num + 1 + i >= n) break;
		ret = min(ret, dfs(num + 1 + i, cnt - i) + dist(num, num + 1 + i));
	}
	return ret;
}

int main()
{
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	//dp[0][0] = 0;
	v.resize(n+1);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		node n;
		n.x = a;
		n.y = b;
		v[i] =n;
	}

	cout << dfs(0, k) << endl;
	
}