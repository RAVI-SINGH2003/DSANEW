#include<bits/stdc++.h>
using namespace std;
int fibonacci_memoization(int n ,vector<int> dp)
{
    if(n<=1) return n ;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fibonacci_memoization(n - 1, dp) + fibonacci_memoization(n - 2, dp);
}
int fibonacci_tabulation(int n ,vector<int> dp)
{
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]= dp[i-1] +dp[i-2];
    }
    return dp[n];
}
int fibonacci_spaceOptimised(int n )
{
    int prev2 = 0, prev1= 1;
    for (int i = 2; i <= n; i++)
    {
       int curr= prev1 + prev2;
        
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    int n;
    cin>>n;
    // int dp[n+1];
    // memset(dp,-1,sizeof dp);
    // or
    vector<int> dp(n+1,-1);
    cout << fibonacci_memoization(n, dp);
    cout << fibonacci_tabulation(n, dp);
    cout << fibonacci_spaceOptimised(n);
}