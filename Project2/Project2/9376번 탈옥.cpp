#include<queue>
#include<iostream>
#include<vector>
#include<string.h>
#include<vector>
using namespace std;

typedef pair<int, int>P;
typedef pair<int, P>PI;
char map[101][101];
int visit[101][101];
int visit2[101][101];
vector<P> start;
int r, c;
int dx[] = {1,0,-1,0};
int dy[] = { 0,1,0,-1 };
int bfs()
{
	visit[start[0].first][start[0].second] = 1;
	priority_queue<PI, vector<PI>, greater<PI>> q;
	q.push({ 0,{start[0].first,start[0].second} });
	while (!q.empty())
	{
		int x = q.top().second.first;
		int y = q.top().second.second;
		int cnt = q.top().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			{
				return cnt;
			}
			if (map[nx][ny] != '*'&&!visit[nx][ny])
			{
				if (map[nx][ny] == '#')
				{
					q.push({ cnt + 1,{nx,ny} });
				}
				else
				{
					q.push({ cnt,{nx,ny} });
				}
				visit[nx][ny] = 1;
			}
			
		}
	}
}

int bfs2()
{
	visit2[start[1].first][start[1].second] = 1;
	priority_queue<PI, vector<PI>, greater<PI>> q;
	q.push({ 0,{start[1].first,start[1].second} });
	while (!q.empty())
	{
		int x = q.top().second.first;
		int y = q.top().second.second;
		int cnt = q.top().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			{
				return cnt;
			}
			if (map[nx][ny] != '*'&&!visit2[nx][ny])
			{
				if (map[nx][ny] == '#')
				{
					if(!visit[nx][ny])
					q.push({ cnt + 1,{nx,ny} });
					else
					q.push({ cnt,{nx,ny} });
				}
				else
				{
					q.push({ cnt,{nx,ny} });
				}
				visit2[nx][ny] = 1;
			}

		}
	}
}
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		memset(visit2, 0, sizeof(visit2));
		start.clear();
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '$')
				{
					start.push_back({ i,j });
				}
			}
		}
		cout << bfs() + bfs2() << endl;
	}

}