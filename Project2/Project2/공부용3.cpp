#include <string>
#include <vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<int> answer;
vector<pair<int, int>>v;
void dfs(string a,int size,int cnt)
{
    if (a.size() == 1)
    {
        v.push_back({cnt,stoi(a)});
        return;
    }
    for (int i = 1; i < size; i++)
    {
        string s = a.substr(0, i);
        string e = a.substr(i);
        if (e.size() != 1 && e[0] == '0')
        {
            continue;
        }
        int num = stoi(s) + stoi(e);
        string str = to_string(num);
        dfs(to_string(num), str.size() , cnt + 1);
    }
}


vector<int> solution(int n) {
    
    string num = to_string(n);

    dfs(num, num.size(), 0);
    sort(v.begin(), v.end());
    answer.push_back(v[0].first);
    answer.push_back(v[0].second);
    return answer;
}

int main()
{
    solution(73425);
    solution(10007);
    solution(9);
}