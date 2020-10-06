#define MAX 9876543210
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
int node, start, arr[10][10], ans = MAX;
bool visit[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> start;
	for (int i = 0; i < node; i++)
		for (int j = 0; j < node; j++)
			cin >> arr[i][j];
	visit[start] = true;
	for (int k = 0; k < node; k++)
	{
		for (int i = 0; i < node; i++)
		{
			for (int j = 0; j < node; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	vector<int>temp;
	for (int i = 0; i < node; i++)
	{
		if (i != start) temp.push_back(i);
	}
	do {
		vector<int> v;
		int dist = 0;
		v.push_back(start);
		for (int i : temp)
		{
			v.push_back(i);
		}
		for (int i = 0; i < v.size() - 1; i++)
		{
			dist += arr[v[i]][v[i+1]];
		}
		ans = min(dist, ans);
	} while (next_permutation(temp.begin(),temp.end()));
	cout << ans;
	return 0;
}