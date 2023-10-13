#include<bits/stdc++.h>
using namespace std;


//1. Memoization
//TC : O(N*N)
//SC : O(N) +  O(N*N)
int f(int i, int aheadi, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return (aheadi == nums.size() || nums[0] < nums[aheadi]);
    }
    if (dp[i][aheadi] != -1)
        return dp[i][aheadi];
    // not take
    int notTake = f(i - 1, aheadi, nums, dp);

    // take
    int take = 0;
    if (aheadi == nums.size() || nums[i] < nums[aheadi])
    {
        take = 1 + f(i - 1, i, nums, dp);
    }
    return dp[i][aheadi] = max(take, notTake);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return f(n - 1, n, nums, dp);
}

//2.Tabulation
// TC : O(N*N)
// SC : O(N*N)

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    for (int aheadi = 1; aheadi <= n; aheadi++)
    {
        if (aheadi == n || nums[0] < nums[aheadi])
            dp[0][aheadi] = 1;
        else
            dp[0][aheadi] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int aheadi = i+1; aheadi <= n; aheadi++)
        {
            int notTake = dp[i - 1][aheadi];

            // take
            int take = 0;
            if (aheadi == nums.size() || nums[i] < nums[aheadi])
            {
                take = 1 + dp[i - 1][i];
            }
            dp[i][aheadi] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}

// SPACE OPTIMIZATION
// TC : O(N*N)
// SC : O(N)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> PREV(n + 1, -1), CUR(n + 1, -1);
    for (int aheadi = 1; aheadi <= n; aheadi++)
    {
        if (aheadi == n || nums[0] < nums[aheadi])
            PREV[aheadi] = 1;
        else
            PREV[aheadi] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int aheadi = i+1; aheadi <= n; aheadi++)
        {
            int notTake = PREV[aheadi];

            // take
            int take = 0;
            if (aheadi == nums.size() || nums[i] < nums[aheadi])
            {
                take = 1 + PREV[i];
            }
            CUR[aheadi] = max(take, notTake);
        }
        PREV = CUR;
    }
    return PREV[n];
}

// 1 array optimization

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> DP(n + 1, -1);
    for (int aheadi = 1; aheadi <= n; aheadi++)
    {
        if (aheadi == n || nums[0] < nums[aheadi])
            DP[aheadi] = 1;
        else
            DP[aheadi] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int aheadi = n; aheadi >= i+1; aheadi--)
        {
            int notTake = DP[aheadi];

            // take
            int take = 0;
            if (aheadi == nums.size() || nums[i] < nums[aheadi])
            {
                take = 1 + DP[i];
            }
            DP[aheadi] = max(take, notTake);
        }
    }
    return DP[n];
}