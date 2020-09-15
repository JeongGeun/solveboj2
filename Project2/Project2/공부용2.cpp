#include <string>
#include <vector>
#include <queue>
using namespace std;

int check[1000001];

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    deque<int>q;
    for (int i = 0; i < 1000001; i++)
        check[i] = 1e9;
    for (auto i : ball)
    {
        q.push_back(i);
    }
    int cnt = 1;
    for (int i = 0; i < order.size(); i++)
    {
        int s = q[0];
        int e = q[q.size() - 1];
        while (1)
        {
            if (check[s] == 1e9 && check[e] == 1e9) break;
            if (check[s] < check[e])
            {
                answer.push_back(s);
                check[s] = 0;
                q.pop_front();
                s = q[0];
            }
            else
            {
                answer.push_back(e);
                check[e] = 0;
                q.pop_back();
                e = q[q.size() - 1];
            }
        }
        if (order[i] == s || order[i] == e)
        {
            if (order[i] == s)
            {
                q.pop_front();
            }
            else
            {
                q.pop_back();
            }
            answer.push_back(order[i]);
        }
        else
        {
            check[order[i]]=cnt;
            cnt++;
        }
    }
    return answer;
}