#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<int> graph[200001];
vector<int> link[200001];
int visit[200001];
int notCycle[200001];
bool res;
void bfs()
{
    queue<int>q;
    q.push(0);
    visit[0] = 1;
    
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        for (int i : graph[num])
        {
            if (!visit[i])
            {
                visit[i] = 1;
                q.push(i);
                link[i].push_back(num);
            }
        }
    }
    memset(visit, 0, sizeof(visit));
}
void dfs(int num)
{
    if (visit[num]) {
        res = false;
        return;
     }
    if (notCycle[num])
    {
        return;
    }
    visit[num] = 1;
    notCycle[num] = 1;
    for (int i : link[num])
    {
        dfs(i);
    }
    visit[num] = 0;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {   
    res = true;
    for (int i = 0; i < path.size(); i++)
    {
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }

    bfs();
    for (int i = 0; i < order.size(); i++)
    {
        link[order[i][1]].push_back(order[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i);
        if (!res) break;
    }

    return res;
}