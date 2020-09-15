#include <string>
#include <vector>
#include <utility>
using namespace std;

int left[] = { 1,2,3,0 };
int right[] = { 3,0,1,2 };

int solution(vector<vector<int>> maze) {
    int answer = 0;

    int x = 0;
    int y = 0;
    int dir = 0;
    int n = maze.size();
    while (1)
    {
        if (x == n - 1 && y == n - 1) break;

        if (dir == 0)
        {
            if (y - 1 >= 0 && !maze[y - 1][x])
            {
                dir = left[dir];
                y--;
                answer++;
            }
            else if (x + 1 < n)
            {
                if (!maze[y][x + 1])
                {
                    x++;
                    answer++;
                }
                else
                {
                    dir = right[dir];
                }
            }
            else
            {
                dir = right[dir];
            }
        }
        else if (dir == 1)
        {
            if (x - 1 >= 0 && !maze[y][x - 1])
            {
                dir = left[dir];
                x--;
                answer++;
            }
            else if (y - 1 >= 0)
            {
                if (!maze[y - 1][x])
                {
                    y--;
                    answer++;
                }
                else
                {
                    dir = right[dir];
                }
            }
            else
            {
                dir = right[dir];
            }
        }
        else if (dir == 2)
        {
            if (y + 1 < n && !maze[y + 1][x])
            {
                dir = left[dir];
                y++;
                answer++;
            }
            else if (x - 1 >= 0)
            {
                if (!maze[y][x - 1])
                {
                    x--;
                    answer++;
                }
                else
                {
                    dir = right[dir];
                }
            }
            else
            {
                dir = right[dir];
            }
        }
        else
        {
            if (x + 1 < n && !maze[y][x + 1])
            {
                dir = left[dir];
                x++;
                answer++;
            }
            else if (y + 1 < n)
            {
                if (!maze[y + 1][x])
                {
                    y++;
                    answer++;
                }
                else {
                    dir = right[dir];
                }
            }
            else {
                dir = right[dir];
            }
        }
    }
    return answer;
}