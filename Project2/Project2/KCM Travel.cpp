#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PI;
typedef pair<P,int> PII;


int m, n, k;
vector<PI> graph[101];
int dist[101][10001];
int visit[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> n >> m >> k;

		for (int i = 0; i <101; i++)
			for (int j = 0; j <= 10000; j++)
				dist[i][j] = 1e9;

		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 101; i++) graph[i].clear();

		for (int a = 0; a < k; a++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			graph[u].push_back({ v,{c,d} });
			//graph[v].push_back({ u,{c,d} });
		}
		priority_queue<PII, vector<PII>, greater<PII>>pq;
		dist[1][0] = 0;
		pq.push({ {0,0},1 });
		while (!pq.empty())
		{
			int cur = pq.top().second;
			int time = pq.top().first.first;
			int cost = pq.top().first.second;
			pq.pop();
			//if (visit[cur]) continue;
			//visit[cur] = 1;
			if (dist[cur][cost] < time) continue;
			for (auto i : graph[cur])
			{
				int next = i.first;
				int ncost = i.second.first;
				int ntime = i.second.second;
				if (cost + ncost > m) continue;

				if (dist[next][cost + ncost] > time + ntime)
				{
					dist[next][cost + ncost] = time + ntime;
					pq.push({ {dist[next][cost + ncost],cost + ncost},next });
				}
			}
			
		}
		int ans = 1e9;
		for (int i = 0; i <= m; i++)
		{
			ans = min(ans, dist[n][i]);
		}
		if (ans == 1e9) cout << "Poor KCM\n";
		else cout << ans << "\n";
	}
}


