#include <bits/stdc++.h>
using namespace std;
//Memoization
int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0 && j >= 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
    {
        return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
    }
    else
    {
        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, s, t, dp);
}

//Tabulation
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    
    //to handle negative base case i added dummy row and column
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = (0LL + dp[i - 1][j - 1] + dp[i - 1][j]) % INT_MAX;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}
//Space optimization
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = curr[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = (0LL + prev[j - 1] + prev[j]) % INT_MAX;
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[m];
}

//Single array optimization
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<int> curr(m + 1, 0);
    curr[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = (0LL + curr[j - 1] + curr[j]) % INT_MAX;
            }
        }
    }

    return curr[m];
}