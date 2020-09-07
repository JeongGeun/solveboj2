#include <string>
#include <vector>
#include <string.h>
using namespace std;
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
typedef pair<int, int> P;
int visit[31][31];

/***
    1. store��� ���͸� �غ��Ѵ�
    2. ��,��,�밢�� ���鼭 2*2��ü�� �� ���� ĳ���͸� Ȯ���Ѵ�
    3. 2���� �ش��ϴ� ��� store�� �ִ´�
    4. store�� ����ִٸ� �� �̻� ���� x, �ƴ϶�� ��ǥ ���� ���鼭 answer�� ������Ű�� board�� ��ĭ(1)���� �Ѵ�.
    5. ���忡 ��ĭ�� �ִٸ� �Ʒ���ǥ�������� �� �Ʒ��� ���鼭 ��������� while������ ���� �ʾҰų� �� ��ǥ���� ������.
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