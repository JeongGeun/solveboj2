#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
struct car {
	int x;
	int y;
	int dir;
};
deque<int>arr[15][15];
int map[15][15];
int n, k;
vector<car> v;

void white(int x,int y,int nx,int ny,int i,int dir)
{
	vector<int>temp;
	int idx = -1;
	int size = arr[x][y].size();
	for (int t = 0; t < arr[x][y].size(); t++)
	{
		if (arr[x][y][t] == i)
		{
			idx = t;
		}
		if (idx >= 0)
		{
			temp.push_back(arr[x][y][t]);
		}
	}
	if (idx != 0) return;
	for (int t = idx; t < size; t++)
	{
		arr[x][y].pop_back();
	}
	for (int t = 0; t < temp.size(); t++)
	{
		arr[nx][ny].push_back(temp[t]);
		v[temp[t]].x = nx;
		v[temp[t]].y = ny;
	}
	v[i].dir = dir;
}
void red(int x, int y, int nx, int ny, int i,int dir)
{
	vector<int>temp;
	int idx = -1;
	int size = arr[x][y].size();
	for (int t = 0; t < arr[x][y].size(); t++)
	{
		if (arr[x][y][t] == i)
		{
			idx = t;
		}
		if (idx >= 0)
		{
			temp.push_back(arr[x][y][t]);
		}
	}
	if (idx != 0) return;
	for (int t = idx; t < size; t++)
	{
		arr[x][y].pop_back();
	}
	for (int t = temp.size() - 1; t >= 0; t--)
	{
		arr[nx][ny].push_back(temp[t]);
		v[temp[t]].x = nx;
		v[temp[t]].y = ny;
	}

	v[i].dir = dir;
}

bool go()
{
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].x;
		int y = v[i].y;
		int dir = v[i].dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || ny <= 0 || nx > n || ny > n)
		{
			if (dir == 0 || dir == 2)
			{
				dir++;
			}
			else
			{
				dir--;
			}
			int nnx = x + dx[dir];
			int nny = y + dy[dir];
			if (nnx <= 0 || nny <= 0 || nnx > n || nny > n) continue;

			if (map[nnx][nny] == 0)
			{
				white(x, y, nnx, nny, i,dir);
				if (arr[nnx][nny].size() >= 4) return true;
			}
			else if (map[nnx][nny] == 1)
			{
				red(x, y, nnx, nny, i,  dir);
				if (arr[nnx][nny].size() >= 4) return true;
			}
		}
		else {
			if (map[nx][ny] == 0)
			{
				white(x, y, nx, ny, i, dir);
				if (arr[nx][ny].size() >= 4) return true;
			}
			else if (map[nx][ny] == 1)
			{
				red(x, y, nx, ny, i, dir);
				if (arr[nx][ny].size() >= 4) return true;
			}
			else
			{
				if (dir == 0 || dir == 2)
				{
					dir++;
				}
				else
				{
					dir--;
				}
				int nnx = x + dx[dir];
				int nny = y + dy[dir];
				if (nnx <= 0 || nny <= 0 || nnx > n || nny > n) continue;

				if (map[nnx][nny] == 0)
				{
					white(x, y, nnx, nny, i, dir);
					if (arr[nnx][nny].size() >= 4) return true;

				}
				else if (map[nnx][nny] == 1)
				{
					red(x, y, nnx, nny, i, dir);
					if (arr[nnx][nny].size() >= 4) return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,--c });
		arr[a][b].push_back(i);
	}
	int time = 1;
	while (time <= 1000)
	{
		if (go()) break;
		time++;
	}
	if (time > 1000) time = -1;
	cout << time << endl;
}