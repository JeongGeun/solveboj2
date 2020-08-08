#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
char arr[51][51];
int dx[] = { 0,1 };
int dy[] = {1,0};

int check()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
			{
				cnt++;
			}
			else { 
				res = max(res, cnt);
				cnt = 1; 
			}
		}
		res = max(res, cnt);
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j][i] == arr[j + 1][i])
			{
				cnt++;
			}
			else { 
				res = max(res, cnt);
				cnt = 1; 
			}
		}
		res = max(res, cnt);
	}


	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int a = 0; a < 2; a++)
			{
				int nx = i + dx[a];
				int ny = j + dy[a];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (arr[i][j] != arr[nx][ny])
				{
					char temp = arr[i][j];
					arr[i][j] = arr[nx][ny];
					arr[nx][ny] = temp;
					if (res < check())
					{
						res = check();
					}
					arr[nx][ny] = arr[i][j];
					arr[i][j] = temp;
				}
			}
		}
	}

	cout << res << endl;


}