#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int n, m, t;
deque<deque<int>> q;
int visit[100][100];
int dx[] = {1,0,0};
int dy[] = {0,1,-1};
void rotate(int x, int d, int k)
{
	if (d == 0)
	{
		for (int i = 0; i < k; i++)
		{
			int num = q[x].back();
			q[x].pop_back();
			q[x].push_front(num);
		}
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			int num = q[x].front();
			q[x].pop_front();
			q[x].push_back(num);
		}
	}

}

int main()
{
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
	{
		deque<int>v;
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		q.push_back(v);
	}
	for (int i = 0; i < t; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		memset(visit, 0, sizeof(visit));
		int temp = x;
		while (temp-1 < n)
		{
			rotate(temp - 1, d, k);
			temp = temp+x;
		}
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (q[a][b] == 1e9) continue;
				for (int dir = 0; dir < 3; dir++)
				{
					int na = a + dx[dir];
					int nb = b + dy[dir];
					if (nb == m)nb = 0;
					else if (nb == -1)nb = m - 1;

					if (na == n) continue;
					if (q[a][b] == q[na][nb])
					{
						visit[a][b] = 1;
						visit[na][nb] = 1;
					}
				}
				
			}
		}
		int psum = 0;
		int pcnt = 0;
		int flag = 0;
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (visit[a][b])
				{
					q[a][b] = 1e9;
					flag = 1;
				}
				else if(q[a][b]!=1e9)
				{
					psum += q[a][b];
					pcnt++;
				}
			}
		}
		if (pcnt == 0) break;
		if (flag == 0)
		{
			double avg = 0;
			avg=psum / (double)pcnt;
			for (int aa = 0; aa < n; aa++)
			{
				for (int bb = 0; bb < m; bb++)
				{
					if (q[aa][bb] != 1e9)
					{
						if (q[aa][bb] > avg) q[aa][bb]--;
						else if (q[aa][bb] < avg)q[aa][bb]++;
					}
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (q[i][j] != 1e9) sum += q[i][j];
	}
	cout << sum<<endl;
}