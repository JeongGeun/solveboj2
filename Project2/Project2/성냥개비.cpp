#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

int arr[101][101];
int visit[101];
vector<int>graph[101];
vector<int> solution(int n, vector<vector<int>> edge)
{
	vector<int> answer;
	int esize = edge.size();
	for (auto i : edge)
	{
		arr[i[0]][i[1]] = 1;
		arr[i[1]][i[0]] = 1;
		graph[i[0]].push_back(i[1]);
		graph[i[1]].push_back(i[0]);

	}
	for (int i = 0; i < esize; i++)
	{
		for (int j = i+1; j < esize; j++)
		{
			arr[edge[i][0]][edge[i][1]] = 0;
			arr[edge[i][1]][edge[i][0]] = 0;
			arr[edge[j][0]][edge[j][1]] = 0;
			arr[edge[j][1]][edge[j][0]] = 0;

			int kcnt = 0;
			for (int k = 0; k < n; k++)
			{
				int cnt = 1;
				if (!visit[k])
				{
					queue<int>q;
					q.push(k);
					visit[k] = 1;
					while (!q.empty())
					{
						int cur = q.front();
						q.pop();
						for (auto i : graph[cur])
						{
							if (arr[cur][i] == 1&&!visit[i])
							{
								visit[i] = 1;
								q.push(i);
								cnt++;
							}
						}
						
					}
					if (cnt != (esize + 1) / 3)
					{
						break;
					}
					else kcnt++;
				}
			}
			memset(visit, 0, sizeof(visit));
			if (kcnt == 3)
			{
				answer.push_back(i);
				answer.push_back(j);
			}
			arr[edge[i][0]][edge[i][1]] = 1;
			arr[edge[j][0]][edge[j][1]] = 1;
			arr[edge[i][1]][edge[i][0]] = 1;
			arr[edge[j][1]][edge[j][0]] = 1;

		}
	}

	for (int i = 0; i < 2; i++)
		cout << answer[i] << endl;
	return answer;
}


int main()
{

	solution(9, { {0,2},{2,1},{2,4},{3,5},{5,4},{5,7},{7,6},{6,8} });

}