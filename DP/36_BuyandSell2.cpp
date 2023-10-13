#include<bits/stdc++.h>
using namespace std;

//Greedy
int stockBuyAndSell(int n, vector<int> &prices)
{
    int pr = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
            pr += prices[i] - prices[i - 1];
    }
    return pr;
}

//Memoization 
// TC : O(n*2)
// SC : O(N) + O(N*2)
int solve(int i, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == prices.size())
    {
        return 0;
    }
    if (dp[i][buy] != -1)
        return dp[i][buy];
    // if allowed to buy
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(i + 1, 0, prices, dp), solve(i + 1, 1, prices, dp));
    }
    else
    {
        profit = max(prices[i] + solve(i + 1, 1, prices, dp), solve(i + 1, 0, prices, dp));
    }
    return dp[i][buy] = profit;
}
int stockBuyAndSell(int n, vector<int> &prices)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solve(0, 1, prices, dp);
}

// Tabulation
//  TC : O(n*2)
//  SC : O(N*2)
int stockBuyAndSell(int n, vector<int> &prices)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    // base case
    dp[n][1] = 0;
    dp[n][0] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            }
            else
            {
                profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
            }
            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}

//Space optimization
//TC : O(n*2)
//SC : O(2)


int stockBuyAndSell(int n, vector<int> &prices)
{
    vector<int> ahead(2, -1), cur(2, -1);

    // base case
    ahead[1] = ahead[0] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[i] + ahead[0], ahead[1]);
            }
            else
            {
                profit = max(prices[i] + ahead[1], ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }

    return ahead[1];
}