#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

typedef pair<int, int> PI;
int n, k, p;
vector<PI>graph[1001];
int visit[1001];
int dist[1001];
int ans = 1e9;

bool dfs(int num)
{
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	memset(visit, 0, sizeof(visit));
	//visit[1] = 1;
	for (int i = 0; i < 1001; i++) dist[i] = 1e9;
	dist[1] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (visit[now]) continue;
		visit[now] = 1;

		for (auto i : graph[now])
		{
			int ncost = cost;
			if (i.second> num)
			{
				ncost++;
			}
			if (dist[i.first] > ncost)
			{
				dist[i.first] = ncost;
				pq.push({ dist[i.first],i.first });
			}
		}

	}
	if (dist[n] > k) return false;

	return true;
}

int main()
{
	cin >> n >> p >> k;
	vector<int> edge;
	edge.push_back(0);
	for (int i = 0; i < p; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b ,c});
		graph[b].push_back({ a ,c });
		edge.push_back(c);
	}
	sort(edge.begin(), edge.end());
	int left = 0;
	int right = edge.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if(dfs(edge[mid]))
		{
			right = mid - 1;
			ans = min(ans, edge[mid]);
		}
		else
		{
			left = mid + 1;
		}
	}
	if (ans == 1e9) ans = -1;
	cout << ans << endl;
}