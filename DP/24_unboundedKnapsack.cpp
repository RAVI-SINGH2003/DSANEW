#include<bits/stdc++.h>
using namespace std;


//1.Memoization
int solve(int i, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (w == 0)
            return 0;
        else if (w >=weight[0])
            return profit[0] * (w / weight[0]);
        else
            return 0;
    }
    if (dp[i][w] != -1)
        return dp[i][w];
    int pick = 0;
    if (w >= weight[i])
        pick = profit[i] + solve(i, w - weight[i], profit, weight, dp);
    int notPick = solve(i - 1, w, profit, weight, dp);

    return dp[i][w] = max(pick, notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(n - 1, w, profit, weight, dp);
}

//2.Tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    dp[0][0] = 0;
    for (int wt = weight[0]; wt <= w; wt ++)
    {
        dp[0][wt] = profit[0] * (wt / weight[0]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int pick = 0;
            if (wt >= weight[i])
                pick = profit[i] + dp[i][wt - weight[i]];
            int notPick = dp[i - 1][wt];
            dp[i][wt] = max(pick, notPick);
        }
    }
    return dp[n - 1][w];
}

//3.space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0), temp(w + 1);

    prev[0] = temp[0] = 0;
    for (int wt = weight[0]; wt <= w; wt ++)
    {
        prev[wt] = profit[0] * (wt / weight[0]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int pick = 0;
            if (wt >= weight[i])
                pick = profit[i] + temp[wt - weight[i]];
            int notPick = prev[wt];
            temp[wt] = max(pick, notPick);
        }
        prev = temp;
    }
    return prev[w];
}

//4. single array optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> dp(w + 1, 0);

    dp[0] = 0;
    for (int wt = 0; wt <= w; wt++)
    {
        dp[wt] = profit[0] * ((int)(wt / weight[0]));
    }

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int pick = 0;
            if (wt >= weight[i])
                pick = profit[i] + dp[wt - weight[i]];
            int notPick = dp[wt];
            dp[wt] = max(pick, notPick);
        }
    }
    return dp[w];
}