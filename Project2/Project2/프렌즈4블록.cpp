#include <string>
#include <vector>
#include <string.h>
using namespace std;
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
typedef pair<int, int> P;
int visit[31][31];

/***
    1. store라는 벡터를 준비한다
    2. 우,하,대각을 보면서 2*2전체가 다 같은 캐릭터를 확인한다
    3. 2번에 해당하는 경우 store에 넣는다
    4. store가 비어있다면 더 이상 진행 x, 아니라면 좌표 수를 세면서 answer를 증가시키고 board를 빈칸(1)으로 한다.
    5. 보드에 빈칸이 있다면 아래좌표에서부터 그 아래를 보면서 비어있으면 while문으로 비지 않았거나 끝 좌표까지 내린다.
***/

vector<string> makeboard(int m,int n,vector<string> board)
{
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int x = i;
            if (board[x][j] != '1')
            {
                char tmp = board[x][j];
                board[x][j] = '1';
                while (1)
                {
                    int nx = x + 1;
                    if (x == m - 1)
                    {
                        board[x][j] = tmp;
                        break;
                    }
                    if (board[nx][j] != '1') {
                        board[x][j] = tmp;
                        break;
                    }
                    else
                    {
                        x = nx;
                    }
                }
            }
        }
    }
    return board;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (1)
    {
        vector<P> store;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                int x = i;
                int y = j;
                int cnt = 0;
                for (int d = 0; d < 3; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == board[x][y]&&board[x][y]!='1') cnt++;
                }
                if (cnt == 3)
                {
                    for (int d = 0; d < 3; d++)
                        store.push_back({ x + dx[d],y + dy[d] });
                    store.push_back({x,y});
                }
            }
        }
        if (store.empty()) break;
        for (auto i : store)
        {
            if (!visit[i.first][i.second])
            {
                visit[i.first][i.second]++;
                answer++;
                board[i.first][i.second] = '1';
            }
        }
        board = makeboard(m, n, board);
        memset(visit, 0, sizeof(visit));
        store.clear();
    }
    return answer;
}

int main()
{
    solution(6, 6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"
        });
}