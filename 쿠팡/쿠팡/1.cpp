#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int>P;
typedef pair<P, P> PI;
int cnt[101];
priority_queue<PI,vector<PI>,greater<PI>> v;

int solution(int n, vector<string>customers)
{
	for (int i = 1; i <= n; i++)
	{
		v.push({ {0,0},{0 ,i} });
	}
	int maxnum = 0;
	for (int t = 0; t < customers.size(); t++)
	{
		string cus = customers[t];
		int mon = stoi(cus.substr(0, 2));
		int day = stoi(cus.substr(3, 2));

		int hour = 3600 * (stoi(cus.substr(6, 2)));
		int min = 60 * (stoi(cus.substr(9, 2)));
		int sec = stoi(cus.substr(12, 2));
		
		int cost = stoi(cus.substr(15, 2))*60;
		
		int vtime = v.top().second.first;
		int vmon = v.top().first.first;
		int vday = v.top().first.second;
		if (t < n)
		{
			vmon = mon;
			vday = day;
			vtime = hour + min + sec + cost;
		}
		else
		{
			vtime =vtime+cost ;
		}

		if (vtime >= 86400)
		{
			vday++;
			vtime -= 86400;
		}
		if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
		{
			if (day > 31)
			{
				vmon++;
				vday = 1;
			}
		}
		else
		{
			if (mon == 2)
			{
				if (day > 28)
				{
					vmon++;
					vday = 1;
				}
			}
			else
			{
				if (day > 30)
				{
					vmon++;
					vday = 1;
				}
			}
		}
		int num = v.top().second.second;
		cnt[num]++;
		maxnum = max(cnt[num], maxnum);
		v.pop();
		v.push({ {mon,day},{vtime,num} });
	}
	cout << maxnum;
	return maxnum;

}
int main()
{
	solution(2, {"02/28 23:59:00 03", "03/01 00:00:00 02", "03/01 00:05:00 01"
});
}