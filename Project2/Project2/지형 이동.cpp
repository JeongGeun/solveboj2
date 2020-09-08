#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include<algorithm>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P>PI;
int visit[301][301];
int parent[100001];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

/***
    1. �⺻���� MST ����
    2. ���� ��ǥ��ȸ�ϸ鼭 ��ٸ��� ���� �ʾƵ� �� �� �ִ� ��ǥ���� �׷����Ѵ�.
    3. �� �� ��,�� ��ǥ��� ���ϸ鼭 �׷��� ��ȣ�� �ٸ� ��ǥ���� q�� �������� �׷��� �ѹ��� �����Ѵ�.
    4. �������� ���� ������� sort�� �� ũ�罺Į �˰����� ����Ͽ� ������ ���� = ��� �� -1 �� �� ������ disjoint-set�Ѵ�
    tips - �ڲ� union-find�� �� 
    return parent[n]=find(n)�� �Ѵ� => parent�� parent�� ã�� �Լ��� �ִ� �ٺ����� ���̴�. �θ��� �θ� �־�����Ѵ�.
    return parent[n]=find(parent[n]) ���� �ؾ��Ѵ�.

***/


int find(int n)
{
    if (parent[n] == -1) return n;
    return parent[n] = find(parent[n]);
}

bool merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[x] = y;
    return true;
}

void bfs(vector<vector<int>> land,int x, int y, int cnt,int h)
{
    queue<P> q;
    q.push({ x,y });
    visit[x][y] = cnt;
    int n=land.size();
    while (!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nnx = nx + dx[i];
            int nny = ny + dy[i];
            if (nnx < 0 || nnx >= n || nny < 0 || nny >= n) continue;
            if (!visit[nnx][nny]&& abs(land[nx][ny]-land[nnx][nny])<=h)
            {
                visit[nnx][nny] = cnt;
                q.push({ nnx,nny });
            }
        }
    }

}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    memset(parent, -1, sizeof(parent));
    int cnt = 1;
    int n = land.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                bfs(land,i,j,cnt, height);
                cnt++;
            }
        }
    }
    cnt--;
    deque<PI>edge;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (visit[x][y] != visit[i][j])
                {
                    edge.push_back({ abs(land[x][y] - land[i][j]),{visit[x][y],visit[i][j]} });
                }
            }
        }
    }
    sort(edge.begin(), edge.end());
    int mcnt = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int cost = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        if (merge(u, v))
        {
            mcnt++;
            answer += cost;
            if (mcnt == cnt - 1) break;
        }
    }
    return answer;
}

int main()
{
    solution({ {1, 4, 8, 10},{5, 5, 5, 5},{10,10,10,10},{10,10,10,20} }, 3);
}