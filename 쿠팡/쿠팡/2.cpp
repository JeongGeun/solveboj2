#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<map>
using namespace std;

//int dp[10001];
int visit[10001];
int s1;
int s2;
vector<int> graph[10001];
map<string, int> m;

int dfs1(int s, int e)
{
	if (s == e)
	{
		return 1;
	}
	if (visit[s]) return visit[s];

	for (auto i : graph[s])
	{
		visit[s]+=dfs1(i, e);
		if (visit[s] > 10007)
		{
			visit[s] = visit[s] % 10007;
		}
	}
	return visit[s];
}
int dfs2(int s, int e)
{
	if (s == e)
	{
		return 1;
	}
	if (visit[s]) return visit[s];
	for (auto i : graph[s])
	{
		visit[s]+=dfs2(i, e);
		if(visit[s]>10007)
		{
			visit[s] = visit[s] % 10007;
		}
	}
	return visit[s];
}
int solution(string depar,string hub,string dest , vector<vector<string>> roads)
{
	int cnt = 0;
	m[depar] = cnt++;
	m[hub] = cnt++;
	m[dest] = cnt++;
	for (auto s : roads)
	{
		if (m.count(s[0]) == 0)
		{
			m[s[0]] = cnt++;
		}
		if (m.count(s[1]) == 0)
		{
			m[s[1]] = cnt++;
		}
		int idx1 = m[s[0]];
		int idx2 = m[s[1]];
		graph[idx1].push_back(idx2);
	}

	s1=dfs1(0, 1);

	memset(visit, 0,sizeof(visit));
	s2=dfs2(1, 2);
	
	int answer = (s1 * s2) % 10007;    
                                                                                                                                                                                                                                                                                                                                                 	return answer;
}
int main()
{

//	solution("SEOUL", "DAEGU", "YEOSU", { {"ULSAN", "BUSAN"},{"DAEJEON", "ULSAN"},{"DAEJEON", "GWANGJU"},{"SEOUL", "DAEJEON"},{"SEOUL", "ULSAN"},{"DAEJEON", "DAEGU"},{"GWANGJU", "BUSAN"},{"DAEGU", "GWANGJU"},{"DAEGU", "BUSAN"},{"ULSAN", "DAEGU"},{"GWANGJU", "YEOSU"
//}, { "BUSAN", "YEOSU"
//}
//		});
	solution("ULSAN", "SEOUL", "BUSAN", {{"SEOUL", "DAEJEON"
}, { "ULSAN", "BUSAN"
}, { "DAEJEON", "ULSAN"
}, { "DAEJEON", "GWANGJU"
}, { "SEOUL", "ULSAN"
}, { "DAEJEON", "BUSAN"
}, { "GWANGJU", "BUSAN"
}});

}