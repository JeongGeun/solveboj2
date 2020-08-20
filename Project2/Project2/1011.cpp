#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long int x, y;
		cin >> x >> y;
		int idx = sqrt(y-x);
		
		if (y-x>idx*(idx+1) )
		{
			cout << 2 * idx+1 << endl;
		}
		else if (y-x<=idx * (idx + 1)&&y-x>idx*idx)
		{
			cout << 2 * idx << endl;
		}
		else
		{
			cout << 2 * idx-1 << endl;
		}

	}

}