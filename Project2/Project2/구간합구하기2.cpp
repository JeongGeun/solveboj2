#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int ll;
int n, m, k;

int arr[1000001];
ll tree[4000001];

ll makeTree(int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = makeTree(start, mid, node * 2) + makeTree(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right)
{
	if (end<left || start>right) return 0;
	if(start>=left&& end<=right)return tree[node];
	
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid+1,end, node*2+1,left,right);
}

void update(int start, int end, int node, int idx,ll dif)
{
	if (idx<start || idx>end) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, node * 2 + 1, idx, dif);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	makeTree(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(0, n - 1, 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else
		{
			cout << sum(0,n-1,1,b-1,c-1) << "\n";
		}
	}


}