#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int>m;
int solution(vector<vector<int>> boxes) {
    int answer = 0;
    for (auto v : boxes)
    {
        for (int i : v)
        {
            m[i]++;
        }
    }
    int cnt = 0;
    int bsize = boxes.size();
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if (i->second % 2 == 0)
        {
            cnt++;
        }
    }
    return bsize-cnt;
}