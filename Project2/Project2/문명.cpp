#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
typedef pair<int, int>P;

int n, k;
int p[100001];
int arr[2001][2001];
vector<P> v;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int find(int num)
{
	if (p[num] < 0) return num;
	p[num] = find(p[num]);
	return p[num];
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (x < y)
	{
		p[x] += p[y];
		p[y] = x;
	}
	else
	{
		p[y] += p[x];
		p[x] = y;
	}

}

int bfs()
{
	deque<P>q;
	for (int i = 0; i < k; i++)
	{
		q.push_back({ v[i].first,v[i].second });
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int nnx = v[i].first + dx[j];
			int nny = v[i].second + dy[j];
			if (nnx<1 || nnx>n || nny<1 || nny>n) continue;
			if (arr[nnx][nny])
				merge(arr[v[i].first][v[i].second], arr[nnx][nny]);
			
		}
	}

	int time = 0;
	int start = k;
	int end = n * n;
	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int nnx = q[i].first + dx[j];
				int nny = q[i].second + dy[j];
				if (nnx<1 || nnx>n || nny<1 || nny>n) continue;
				if (arr[nnx][nny])
					merge(arr[q[i].first][q[i].second], arr[nnx][nny]);

			}
		}


		if (p[1] + k == 0) break;
		for (int i = 0; i < qsize; i++)
		{
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop_front();
			for (int j = 0; j < 4; j++)
			{
				int nnx = nx + dx[j];
				int nny = ny + dy[j];
				if (nnx<1 || nnx>n || nny<1 || nny>n) continue;
				if (!arr[nnx][nny])
				{
					q.push_back({ nnx,nny });
					arr[nnx][nny] = arr[nx][ny];
				}
				else
				{
					merge(arr[nx][ny], arr[nnx][nny]);
				}
			}

		}
		time++;
	}
	return time;
}

int main()
{
	memset(p, -1, sizeof(p));
	cin >> n >> k;
	int cnt = 1;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = cnt++;
		v.push_back({ a,b });
	}
	cout << bfs() << endl;

}