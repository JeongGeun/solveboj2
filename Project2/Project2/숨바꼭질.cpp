#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<int>adj[20001];
int visit[20001];

void bfs()
{
	memset(visit, -1, sizeof(visit));
	queue<pair<int, int>> q;
	visit[1] = 0;
	q.push({ 1,0 });
	int maxcnt = 0;
	vector<pair<int, int>>v;
	int rcnt = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i : adj[x])
		{
			if (visit[i] == -1)
			{
				visit[i] = visit[x] + 1;
				q.push({ i,visit[i] });
				maxcnt = max(maxcnt, visit[i]);
			}
		}
	}
	
	for (int i=1;i<=n;i++)
	{
		if (visit[i] == maxcnt)
		{
			v.push_back({ i,maxcnt });
			rcnt++;
		}
	}
	cout << v[0].first <<" "<< maxcnt << " " << rcnt << endl;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs();


}