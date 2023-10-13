<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

//TC: O(2^N) APPROXIMATELY
//SC :O(N)
  
int helper_R(vector<int> &nums, int n)
{
    if (n == 0)
        return nums[n];
    if (n < 0)
        return 0;
    int pick = nums[n] + helper_R(nums, n - 2);
    int nonPick = 0 + helper_R(nums, n - 1);
    return max(pick, nonPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    return helper_R(nums, nums.size() - 1);
}
// TC: O(N) APPROXIMATELY
// SC :O(N) + O(N)

int helper_M(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0)
        return nums[0];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int pick = nums[n] + helper_M(nums, n - 2, dp);
    int nonPick = 0 + helper_M(nums, n - 1, dp);
    return dp[n] = max(pick, nonPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    vector<int> dp(nums.size(), -1);
    return helper_M(nums, nums.size() - 1, dp);
}

// TC: O(N) APPROXIMATELY
// SC :O(N)
int helper_T(vector<int> &nums, int n, vector<int> &dp)
{

    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = 0 + dp[i - 1];
        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    vector<int> dp(nums.size(), -1);
    return helper_T(nums, nums.size(), dp);
}
//Space Optimization

// TC: O(N) APPROXIMATELY
// SC :O(1)
 
int helper_SC(vector<int> &nums, int n)
{

    int prev1 = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev1;
        int curr = max(pick, nonPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    vector<int> dp(nums.size(), -1);
    return helper_SC(nums, nums.size());
=======
#include <bits/stdc++.h>
using namespace std;

//TC: O(2^N) APPROXIMATELY
//SC :O(N)
  
int helper_R(vector<int> &nums, int n)
{
    if (n == 0)
        return nums[n];
    if (n < 0)
        return 0;
    int pick = nums[n] + helper_R(nums, n - 2);
    int nonPick = 0 + helper_R(nums, n - 1);
    return max(pick, nonPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    return helper_R(nums, nums.size() - 1);
}
// TC: O(N) APPROXIMATELY
// SC :O(N) + O(N)

int helper_M(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0)
        return nums[0];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int pick = nums[n] + helper_M(nums, n - 2, dp);
    int nonPick = 0 + helper_M(nums, n - 1, dp);
    return dp[n] = max(pick, nonPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    vector<int> dp(nums.size(), -1);
    return helper_M(nums, nums.size() - 1, dp);
}

// TC: O(N) APPROXIMATELY
// SC :O(N)
int helper_T(vector<int> &nums, int n, vector<int> &dp)
{

    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = 0 + dp[i - 1];
        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    vector<int> dp(nums.size(), -1);
    return helper_T(nums, nums.size(), dp);
}
//Space Optimization

// TC: O(N) APPROXIMATELY
// SC :O(1)
 
int helper_SC(vector<int> &nums, int n)
{

    int prev1 = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev1;
        int curr = max(pick, nonPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    vector<int> dp(nums.size(), -1);
    return helper_SC(nums, nums.size());
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}