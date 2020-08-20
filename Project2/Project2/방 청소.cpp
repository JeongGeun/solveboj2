#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int parent[300001];
int desk[300001];
int n, l;

int find(int num)
{
	if (parent[num] < 0) return num;
	return parent[num] = find(parent[num]);
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	parent[x] = y;
}

int main()
{
	cin >> n >> l;
	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < l;i++)
	{
		int a, b;
		cin >> a >> b;
		bool flag = false;
		if (!desk[a])
		{
			desk[a] = 1;
			//merge(a, b);
			cout << "LADICA\n";
		}
		else if (!desk[b])
		{
			desk[b] = 1;
			//merge(a, b);
			cout << "LADICA\n";
		}
		else if (!desk[find(a)])
		{
			desk[find(a)] = 1;
			merge(a,b);
			cout << "LADICA\n";
		}
		else if (!desk[find(b)])
		{
			desk[find(b)] = 1;
			merge(a, b);
			cout << "LADICA\n";
		}
		else
		{
			cout << "SMECE\n";
		}
	}




}