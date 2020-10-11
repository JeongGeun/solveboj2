#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int>left;
	priority_queue<int, vector<int>, greater<int>>right;
	for (int i = 1; i <= n; i++)
	{
		int num;

		cin >> num;
		if (i == 1)
		{
			left.push(num);
			cout << num<< endl;
			continue;
		}
		int mid = left.top();
		if (num >= mid)
		{
			right.push(num);
		}
		else
		{
			left.push(num);
		}
		if (right.size() > left.size())
		{
			int top = right.top();
			right.pop();
			left.push(top);
		}
		else if (left.size() > right.size() + 1)
		{
			int top = left.top();
			left.pop();
			right.push(top);
		}
		cout << left.top() << endl;
	}
}