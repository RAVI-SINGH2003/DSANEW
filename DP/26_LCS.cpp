#include <string>
#include <vector>
using namespace std;

// 1.Memoization
int solve(int idx1, int idx2, string s, string t, vector<vector<int>> &dp)
{
    if (idx1 < 0 || idx2 < 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];
    if (s[idx1] == t[idx2])
    {
        return dp[idx1][idx2] = 1 + solve(idx1 - 1, idx2 - 1, s, t, dp);
    }
    int op1 = solve(idx1 - 1, idx2, s, t, dp);
    int op2 = solve(idx1, idx2 - 1, s, t, dp);
    return dp[idx1][idx2] = max(op1, op2);
}
int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, s, t, dp);
}

// 2. Tabulation

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int idx1 = 0; idx1 < n; idx1++)
    {
        for (int idx2 = 0; idx2 < m; idx2++)
        {
            // match
            if (s[idx1] == t[idx2])
            {
                dp[idx1][idx2] = (idx1 - 1 >= 0 && idx2 - 1 >= 0) ? (1 + dp[idx1 - 1][idx2 - 1]) : 1;
            }
            // not match
            else
            {
                int op1 = 0, op2 = 0;
                if (idx1 - 1 >= 0)
                    op1 = dp[idx1 - 1][idx2];
                if (idx2 - 1 >= 0)
                    op2 = dp[idx1][idx2 - 1];
                dp[idx1][idx2] = max(op1, op2);
            }
        }
    }
    return dp[n - 1][m - 1];
}

// can also be done as follows
// recommneded way

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int N = 0; N < n + 1; N++)
    {
        dp[N][0] = 0;
    }
    for (int M = 0; M < m + 1; M++)
    {
        dp[0][M] = 0;
    }
    for (int idx1 = 1; idx1 < n + 1; idx1++)
    {
        for (int idx2 = 1; idx2 < m + 1; idx2++)
        {
            // match
            if (s[idx1 - 1] == t[idx2 - 1])
            {
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            }
            // not match
            else
            {
                int op1 = dp[idx1 - 1][idx2];
                int op2 = dp[idx1][idx2 - 1];
                dp[idx1][idx2] = max(op1, op2);
            }
        }
    }
    return dp[n][m];
}

// 3.space optimization
int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<int> prev(m, 0), curr(m, 0);
    for (int idx1 = 0; idx1 < n; idx1++)
    {
        for (int idx2 = 0; idx2 < m; idx2++)
        {
            // match
            if (s[idx1] == t[idx2])
            {
                curr[idx2] = idx2 - 1 >= 0 ? (1 + prev[idx2 - 1]) : 1;
            }
            // not match
            else
            {
                int op1 = 0, op2 = 0;
                op1 = prev[idx2];
                if (idx2 - 1 >= 0)
                    op2 = curr[idx2 - 1];
                curr[idx2] = max(op1, op2);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}