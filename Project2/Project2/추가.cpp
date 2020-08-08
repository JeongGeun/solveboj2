#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int start = 0;
	vector<int>v;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int m = n;
	for (int i = 0; i < v.size(); i++)
	{
		start = max(start,v[i]*(m--));
	}
	cout << start << endl;
}