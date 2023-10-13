#include<bits/stdc++.h>
using namespace std;

// TC : O(n*m)
// SC : O(n*m) + O(n+m)

bool f(int pidx, int sidx, string s, string p, vector<vector<int>> &dp)
{
    if (sidx < 0 && pidx < 0)
        return 1;
    if (pidx < 0 && sidx >= 0)
        return 0;
    if (sidx < 0 && pidx >= 0)
    {
        for (int k = pidx; k >= 0; k--)
        {
            if (p[k] != '*')
                return 0;
        }
        return 1;
    }
    if (dp[sidx][pidx] != -1)
        return dp[sidx][pidx];
    if (s[sidx] == p[pidx] || p[pidx] == '?')
        return dp[sidx][pidx] = f(pidx - 1, sidx - 1, s, p, dp);
    else if (p[pidx] == '*')
    {
        return dp[sidx][pidx] = f(pidx - 1, sidx, s, p, dp) || f(pidx, sidx - 1, s, p, dp);
    }
    return dp[sidx][pidx] = 0;
}

bool wildcardMatching(string p, string s)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(m - 1, n - 1, s, p, dp);
}

// TC : O(n*m)
// SC : O(n*m) 
bool wildcardMatching(string p, string s)
{

    int n = s.size();
    int m = p.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    bool flag = false;
    for (int idx = 1; idx <= m; idx++)
    {
        if (p[idx - 1] == '*' && !flag)
        {
            dp[0][idx] = 1;
        }
        else
        {
            dp[0][idx] = 0;
            flag = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return dp[n][m];
}
// TC : O(n*m)
// SC : O(m)
bool wildcardMatching(string p, string s)
{

    int n = s.size();
    int m = p.size();

    vector<int> prev(m + 1, -1), cur(m + 1, -1);

    prev[0] = 1;
    cur[0] = 0;
    bool flag = false;
    for (int idx = 1; idx <= m; idx++)
    {
        if (p[idx - 1] == '*' && !flag)
        {
            prev[idx] = 1;
        }
        else
        {
            prev[idx] = 0;
            flag = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                cur[j] = prev[j - 1];
            }
            else if (p[j - 1] == '*')
            {
                cur[j] = (prev[j] || cur[j - 1]);
            }
            else
            {
                cur[j] = 0;
            }
        }
        prev = cur;
    }

    return prev[m];
}

//using  for loop
bool fun(int pidx, int sidx, string &s, string &p, vector<vector<int>> &dp)
{
    if (sidx < 0 && pidx < 0)
        return 1;
    if (pidx < 0 && sidx >= 0)
        return 0;
    if (sidx < 0 && pidx >= 0)
    {
        for (int k = pidx; k >= 0; k--)
        {
            if (p[k] != '*')
                return 0;
        }
        return 1;
    }
    if (dp[sidx][pidx] != -1)
        return dp[sidx][pidx];
    if (s[sidx] == p[pidx] || p[pidx] == '?')
        return dp[sidx][pidx] = fun(pidx - 1, sidx - 1, s, p, dp);
    else if (p[pidx] == '*')
    {
        for (int k = sidx; k >= -1; k--)
        {
            if (fun(pidx - 1, k, s, p, dp))
            {
                return dp[sidx][pidx] = 1;
            }
        }
        return dp[sidx][pidx] = 0;
    }
    return dp[sidx][pidx] = 0;
}
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(m - 1, n - 1, s, p, dp);
}