#include<bits/stdc++.h>
using namespace std;

// TC : O(n*2*3)
// SC : O(n*2*3) +  O(n)
const int N = 1e5 + 1;
int dp[N][2][3];
int solve(int i, int buy, int count, vector<int> &prices)
{
    if (i == prices.size() || count == 2)
    {
        return 0;
    }
    if (dp[i][buy][count] != -1)
        return dp[i][buy][count];
    // if allowed to buy
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(i + 1, 0, count, prices), solve(i + 1, 1, count, prices));
    }
    else
    {
        profit = max(prices[i] + solve(i + 1, 1, count + 1, prices), solve(i + 1, 0, count, prices));
    }
    return dp[i][buy][count] = profit;
}

int maxProfit(vector<int> &price)
{
    int n = price.size();

    memset(dp, -1, sizeof(dp));

    return solve(0, 1, 0, price);
}

// Tabulation
//TC : O(n*2*3)
//SC : O(n*2*3)

const int N = 1e5 + 1;
int dp[N][2][3];
int solve(int i, int buy, int count, vector<int> &prices)
{
    if (i == prices.size() || count == 2)
    {
        return 0;
    }
    if (dp[i][buy][count] != -1)
        return dp[i][buy][count];
    // if allowed to buy
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(i + 1, 0, count, prices), solve(i + 1, 1, count, prices));
    }
    else
    {
        profit = max(prices[i] + solve(i + 1, 1, count + 1, prices), solve(i + 1, 0, count, prices));
    }
    return dp[i][buy][count] = profit;
}

int maxProfit(vector<int> &price)
{
    int n = price.size();

    memset(dp, -1, sizeof(dp));

    for (int buy = 0; buy <= 1; buy++)
    {
        for (int count = 0; count <= 2; count++)
        {
            dp[n][buy][count] = 0;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            dp[i][buy][2] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {

        for (int buy = 0; buy <= 1; buy++)
        {

            for (int count = 0; count <= 1; count++)
            {

                int profit = 0;
                if (buy)
                {
                    profit = max(-price[i] + dp[i + 1][0][count], dp[i + 1][1][count]);
                }
                else
                {
                    profit = max(price[i] + dp[i + 1][1][count + 1], dp[i + 1][0][count]);
                }
                dp[i][buy][count] = profit;
            }
        }
    }

    return dp[0][1][0];
}

//Space optimization
//TC : O(n*2*3)
//SC : O(2*3)
int maxProfit(vector<int> &price)
{
    int n = price.size();
    int ahead[2][3], cur[2][3];
    memset(ahead, -1, sizeof(ahead));
    memset(cur, -1, sizeof(cur));

    for (int buy = 0; buy <= 1; buy++)
    {
        for (int count = 0; count <= 2; count++)
        {
            ahead[buy][count] = cur[buy][count] = 0;
        }
    }

    for (int buy = 0; buy <= 1; buy++)
    {
        ahead[buy][2] = cur[buy][2] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {

        for (int buy = 0; buy <= 1; buy++)
        {

            for (int count = 0; count <= 1; count++)
            {

                int profit = 0;
                if (buy)
                {
                    profit = max(-price[i] + ahead[0][count], ahead[1][count]);
                }
                else
                {
                    profit = max(price[i] + ahead[1][count + 1], ahead[0][count]);
                }
                cur[buy][count] = profit;
            }
        }
        for (int b = 0; b <= 1; b++)
        {
            for (int c = 0; c <= 2; c++)
            {
                ahead[b][c] = cur[b][c];
            }
        }
    }

    return ahead[1][0];
}