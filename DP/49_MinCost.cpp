#include<bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts, dp) + solve(ind + 1, j, cuts, dp));
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(begin(cuts), end(cuts));
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return solve(1, cuts.size() - 2, cuts, dp);
}

#include <bits/stdc++.h>

int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts, dp) + solve(ind + 1, j, cuts, dp));
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(begin(cuts), end(cuts));
    vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));

    for (int i = 0; i < cuts.size(); i++)
    {
        for (int j = 0; j < cuts.size(); j++)
        {
            if (i > j)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = cuts.size() - 2; i >= 1; i--)
    {
        for (int j = 1; j <= cuts.size() - 2; j++)
        {
            if (i > j)
                continue;
            int mini = 1e9;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][cuts.size() - 2];
}