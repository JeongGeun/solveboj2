#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int>P;
vector<P> graph[51];
int dist[51];
int visit[51];
/***
    �⺻���� ���ͽ�Ʈ�� ����
    1. dist�� ���Ѵ�� �ʱ�ȭ ��Ų��.
    2. �׷����� �׸���.
    3. �켱���� ť�� ����Ͽ� dist�� �����Ѵ�.
    4. �Ÿ��� k���� ���� ����� ������ ����
***/
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 0; i <= N; i++)
        dist[i] = 1e9;

    for (auto v : road)
    {
        graph[v[0]].push_back({ v[1],v[2] });
        graph[v[1]].push_back({ v[0],v[2] });
    }
    dist[1] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({ 0,1 });
    while (!q.empty())
    {
        int cur = q.top().second;
        int cost = q.top().first;
        q.pop();
        if (visit[cur]) continue;
        visit[cur]++;
        for (auto i : graph[cur])
        {
            if (dist[i.first] > dist[cur] + i.second)
            {
                dist[i.first] = dist[cur] + i.second;
                q.push({ dist[i.first],i.first });
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
        {
            answer++;
        }
    }

    return answer;
}
int main()
{
    solution(5, {{1, 2, 1
}, { 2, 3, 3
}, { 5, 2, 2
}, { 1, 4, 2
}, { 5, 3, 1
}, { 5, 4, 2
}}, 3);
}