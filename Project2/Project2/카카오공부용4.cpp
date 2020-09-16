#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/***
    �÷��̵� ���� ���빮�� 
    
    1. ��� ����� dist�� ���Ѵ�� �����Ѵ�.
    2. �׷����� �׸���.
    3. �÷��̵� ���� �˰����� �̿��� �� ��帶���� �ִ� �Ÿ��� ����Ѵ�.
    4. 1~N ��� �� ��� ������ �𸣱� ������ 1���� N���� ������ ������ �����Ͽ� (start���� i)+(a���� i���� �Ÿ�)+(b���� i���� �Ÿ�)<answer�̸� answer���� 
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