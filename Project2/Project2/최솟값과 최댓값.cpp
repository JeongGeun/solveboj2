#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;


int n, m;
int seg[400001][2];
int arr[100001];

int makeMinTree(int s, int e, int node,int num)
{
	if (s == e) return seg[node][num] = arr[s];
	int mid = (s + e) / 2;
	return seg[node][num]=min(makeMinTree(s, mid, node * 2, num), makeMinTree(mid+1,e, node * 2+1, num));
}

int makeMaxTree(int s, int e, int node, int num)
{
	if (s == e) return seg[node][num] = arr[s];
	int mid = (s + e) / 2;
	return seg[node][num] = max(makeMaxTree(s, mid, node * 2, num), makeMaxTree(mid + 1, e, node * 2 + 1, num));
}

int searchminTree(int s, int e, int left, int right, int node,int num)
{
	if (s > right || e < left) return 1e9+1;
	if (s >= left && e <= right) return seg[node][num];
	int mid = (s + e) / 2;
	return min(searchminTree(s, mid, left, right, node * 2, num), searchminTree(mid + 1, e, left, right, node * 2 + 1, num));
}


int searchmaxTree(int s, int e, int left, int right, int node, int num)
{
	if (s > right || e < left) return -1;
	if (s >= left && e <= right) return seg[node][num];
	int mid = (s + e) / 2;
	return max(searchmaxTree(s, mid, left, right, node * 2, num), searchmaxTree(mid + 1, e, left, right, node * 2 + 1, num));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	makeMinTree(0, n - 1, 1,0);
	makeMaxTree(0, n - 1, 1,1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << searchminTree(0, n - 1, a-1, b-1, 1, 0) << " " << searchmaxTree(0, n - 1, a-1, b-1, 1, 1) << "\n";
	}


}