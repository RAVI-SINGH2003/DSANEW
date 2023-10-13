#include <bits/stdc++.h>
using namespace std;

// TC : O(N*N*2*N)
// SC : O(N*N*2 +) + O(N)
int mod = 1e9 + 7;
long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long long ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        long long lt = f(i, k - 1, 1, exp, dp);
        long long lf = f(i, k - 1, 0, exp, dp);
        long long rt = f(k + 1, j, 1, exp, dp);
        long long rf = f(k + 1, j, 0, exp, dp);
        if (exp[k] == '&')
        {
            if (isTrue)
            {
                ways = (ways + (lt * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
        else if (exp[k] == '|')
        {
            if (isTrue)
            {
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lt * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (lf * rf) % mod) % mod;
            }
        }
        else
        {
            if (isTrue)
            {
                ways = (ways + (lf * rt) % mod + (lt * rf) % mod) % mod;
            }
            else
            {
                ways += ((lf * rf) % mod + (lt * rt) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}

// TC : O(N*N*2*N)
// SC : O(N*N*2 +)
int evaluateExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));

    for (int i = 0; i < n; i++)
    {
        dp[i][i][1] = (exp[i] == 'T');
        dp[i][i][0] = (exp[i] == 'F');
    }
    //i>j case below
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        //j = i+1 because j<=i case already covered
        for (int j = i+1; j < n; j++)
        {
            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                long long ways = 0;
                for (int k = i + 1; k <= j - 1; k += 2)
                {
                    long long lt = dp[i][k - 1][1];
                    long long lf = dp[i][k - 1][0];
                    long long rt = dp[k + 1][j][1];
                    long long rf = dp[k + 1][j][0];
                    if (exp[k] == '&')
                    {
                        if (isTrue)
                        {
                            ways = (ways + (lt * rt) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
                        }
                    }
                    else if (exp[k] == '|')
                    {
                        if (isTrue)
                        {
                            ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lt * rt) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (lf * rf) % mod) % mod;
                        }
                    }
                    else
                    {
                        if (isTrue)
                        {
                            ways = (ways + (lf * rt) % mod + (lt * rf) % mod) % mod;
                        }
                        else
                        {
                            ways += ((lf * rf) % mod + (lt * rt) % mod) % mod;
                        }
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}