#include <bits/stdc++.h>
using namespace std;


//1. Memoization :

int solve(int W, int wt[], int val[], int n, int i, auto &dp)
{

    if (i == 0)
    {
        if (W >= wt[0])
            return val[0];
        else
            return 0;
    }
    if (dp[i][W] != -1)
        return dp[i][W];
    // pick

    int pick = 0;
    if (W >= wt[i])
        pick = val[i] + solve(W - wt[i], wt, val, n, i - 1, dp);

    // nont pick
    int notPick = solve(W, wt, val, n, i - 1, dp);

    return dp[i][W] = max(pick, notPick);
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(W, wt, val, n, n - 1, dp);
}

// 2. Tabulation (Bottom-up)

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int w = wt[0]; w <= W; w++)
    {
        dp[0][w] = val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            int pick = 0;
            if (w >= wt[i])
                pick = val[i] + dp[i - 1][w - wt[i]];
            int notPick = dp[i - 1][w];
            dp[i][w] = max(pick, notPick);
        }
    }
    return dp[n - 1][W];
}

//3. space optimization :
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> dp(W + 1, 0);
    for (int w = wt[0]; w <= W; w++)
    {
        dp[w] = val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = W; w >= 0; w--)
        {
            int pick = 0;
            if (w >= wt[i])
                pick = val[i] + dp[w - wt[i]];
            int notPick = dp[w];
            dp[w] = max(pick, notPick);
        }
    }
    return dp[W];
}