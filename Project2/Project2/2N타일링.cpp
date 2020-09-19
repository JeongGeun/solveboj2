#include <string>
#include <vector>

using namespace std;

long long int dp[60001];

int solution(int n) {
    int answer = 0;
    long long int maxnum = 1000000007;
    
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % maxnum;
    }
    return dp[n];
}