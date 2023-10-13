#include<bits/stdc++.h>
using namespace std;

//1. Memoization
int solve(vector<int> &num, int idx, int x, vector<vector<int>> &dp)
{
    if (x == 0)
    {
        return 0;
    }
    if (idx == 0)
    {
        return (x % num[0] == 0) ? (x / num[idx]) : 1e8;
    }
    if (dp[idx][x] != -1)
        return dp[idx][x];
    // pick
    int pick = 1e8;
    if (x >= num[idx])
        pick = 1 + solve(num, idx, x - num[idx], dp);
    int notPick = solve(num, idx - 1, x, dp);
    return dp[idx][x] = min(pick, notPick);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = solve(num, n - 1, x, dp);
    return ans == 1e8 ? -1 : ans;
}
//2.Tabulation
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 1e8));
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    for (int tar = num[0]; tar <= x; tar += num[0])
        dp[0][tar] = tar / num[0];
    for (int i = 1; i < n; i++)
    {
        for (int tar = 1; tar <= x; tar++)
        {
            int pick = 1e8;
            if (tar >= num[i])
                pick = 1 + dp[i][tar - num[i]];
            int notPick = dp[i - 1][tar];
            dp[i][tar] = min(pick, notPick);
        }
    }
    int ans = dp[n - 1][x];
    return ans == 1e8 ? -1 : ans;
}

//3. Space optimization

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> dp(x + 1, 1e8);
    vector<int> temp = dp;
    for (int i = 0; i < n; i++)
    {
        dp[0] = temp[0] = 0;
    }
    for (int tar = num[0]; tar <= x; tar += num[0])
        dp[tar] = temp[tar] = tar / num[0];
    for (int i = 1; i < n; i++)
    {
        //  temp[0] = 0;
        for (int tar = 1; tar <= x; tar++)
        {
            int pick = 1e8;
            if (tar >= num[i])
                pick = 1 + temp[tar - num[i]];
            int notPick = dp[tar];
            temp[tar] = min(pick, notPick);
        }
        dp = temp;
    }
    int ans = dp[x];
    return ans == 1e8 ? -1 : ans;
}