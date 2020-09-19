#include <string>
#include <vector>
#include<queue>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> P;
typedef pair<int,P> PI;
int visit[501];
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<PI, vector<PI>, greater<PI>> q;
    vector<P> v;
    int idx = 0;
    for (auto i : jobs)
    {
        int a = i[0];
        int b = i[1];
        //  q.push({a,b});
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end());
    q.push({ v[0].second,{v[0].first, 0} });
    int time = v[0].first;
    visit[0]++;
    vector<int> ans;
    while (!q.empty())
    {
        int s = q.top().second.first;
        int btime = q.top().first;
        int index = q.top().second.second;
        q.pop();
        time += btime;
        ans.push_back(time - s);
        for (int i=0;i<v.size();i++)
        {
            if (v[i].first <= time&&!visit[i])
            {
                q.push({ v[i].second,{v[i].first ,i }});
                visit[i]++;
            }
            
            if (v[i].first > time) break;
        }

        if (q.empty() && ans.size() != v.size())
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (!visit[i])
                {
                    q.push({ v[i].second,{v[i].first ,i } });
                    time = v[i].first;
                    visit[i]++;
                    break;
                }
            }
        }
    }
    for (int i : ans) answer += i;
    answer = answer/ ans.size();
    return answer;
}

int main()
{
    solution({{0, 3
}, { 1, 9
}, { 2, 6
}});
}