#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PI;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int visit[26][26][4];

struct car {
    int x;
    int y;
    int prev;
    int cost;
};

int solution(vector<vector<int>> board) {
    int answer = 1e9;
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int d = 0; d < 4; d++)
                visit[i][j][d] = 1e9;
        }
    }
    queue<car>q;
    q.push({ 0,0,1,0 });
    q.push({ 0,0,2,0 });
    visit[0][0][1]=0;
    visit[0][0][2]=0;
    
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        int prev = q.front().prev;
        q.pop();
        if (x == n - 1 && y == n - 1)
        {
            answer = min(answer, cost);
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (!board[nx][ny])
            {
                int ncost = cost;
                if (prev%2==0)
                {
                    if (i % 2 == 0) ncost += 100;
                    else ncost += 600;
                }
                else
                {
                    if (i % 2 == 1) ncost += 100;
                    else ncost += 600;
                }
                if (visit[nx][ny][i] > ncost)
                {
                    visit[nx][ny][i] = ncost;
                    q.push({ nx,ny,i,ncost });
                }
            }
        }
    }
    return answer;
}