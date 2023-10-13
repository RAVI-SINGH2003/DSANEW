
#include<bits/stdc++.h>
using namespace std;

int dp[50001][2];
int solve(int i, int buy, vector<int> &prices, int fee)
{
    if (i >= prices.size())
    {
        return 0;
    }
    if (dp[i][buy] != -1)
        return dp[i][buy];
    // if allowed to buy
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(i + 1, 0, prices, fee), solve(i + 1, 1, prices, fee));
    }
    else
    {
        profit = max(prices[i] + solve(i + 1, 1, prices, fee) - fee, solve(i + 1, 0, prices, fee));
    }
    return dp[i][buy] = profit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();

    memset(dp, -1, sizeof(dp));

    return solve(0, 1, prices, fee);
}