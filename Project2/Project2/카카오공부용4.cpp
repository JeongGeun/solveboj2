#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int graph[201][201];
int visit[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
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
    for (int i = 1; i <= n; i++)
    {
        if (graph[s][i] + graph[i][a] < sa)
        {
            sa = graph[s][i] + graph[i][a];
        }

        if (graph[s][i] + graph[i][b] < sb)
        {
            sb = graph[s][i] + graph[i][b];
        }
    }
    answer = graph[s][a] + graph[s][b];
    return answer;
}