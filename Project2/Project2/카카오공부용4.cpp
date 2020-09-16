#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/***
    플로이드 워셜 응용문제 
    
    1. 모든 노드의 dist를 무한대로 세팅한다.
    2. 그래프를 그린다.
    3. 플로이드 워셜 알고리즘을 이용해 각 노드마다의 최단 거리를 계산한다.
    4. 1~N 노드 중 어디서 내릴지 모르기 때문에 1부터 N까지 내리는 점으로 지정하여 (start에서 i)+(a에서 i까지 거리)+(b에서 i까지 거리)<answer이면 answer갱신 
***/
int graph[201][201];
int visit[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            if(i!=j)
            graph[i][j] = 1e9;
        }
    }

    for (auto v : fares)
    {
        graph[v[0]][v[1]] = v[2];
        graph[v[1]][v[0]] = v[2];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    int sa = graph[s][a];
    int sb = graph[s][b];
    answer = sa+sb;
    for (int i = 1; i <= n; i++)
    {
        if (graph[s][i] + graph[i][a]+ graph[i][b] < answer)
        {
            answer = graph[s][i] + graph[i][a] + graph[i][b];
        }
    }
    
    return answer;
}