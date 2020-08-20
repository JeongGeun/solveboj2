#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vector<int>v;
		vector<int>v2;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '(')
			{
				v.push_back(0);
			}
			else
			{
				if (!v.empty())
				{
					v.pop_back();
				}
				else
				{
					v2.push_back(1);
				}
			}
		}
		if (!v.empty() || !v2.empty())
		{
			cout << "NO\n";
		}
		else cout << "YES\n";
	}


}