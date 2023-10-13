#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int maxi = -1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int currCost = nums[i - 1] * nums[ind] * nums[j + 1];
        int leftCost = solve(i, ind - 1, nums, dp);
        int rightCost = solve(ind + 1, j, nums, dp);
        int cost = currCost + leftCost + rightCost;
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    return solve(1, nums.size() - 2, nums, dp);
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i > j)
                dp[i][j] = 0;
        }
    }
    for (int i = nums.size() - 2; i >= 1; i--)
    {
        // j<i case already covered so j>=i cases need to be covered
        for (int j = i; j <= nums.size() - 2; j++)
        {
            int maxi = -1e9;
            for (int ind = i; ind <= j; ind++)
            {
                int currCost = nums[i - 1] * nums[ind] * nums[j + 1];
                int leftCost = dp[i][ind - 1];
                int rightCost = dp[ind + 1][j];
                int cost = currCost + leftCost + rightCost;
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][nums.size() - 2];
}