<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/house-robber-ii/
// same as previous problem
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
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    long long int res1 = helper_SC(temp1, temp1.size());

    long long int res2 = helper_SC(temp2, temp2.size());
    return max(res1, res2);
}

//------------------- MY SOLUTIONS ---------------------------
//Memoization
// class Solution
// {
// public:
//     int helper(vector<int> &nums, int n, vector<int> &dp, bool isPicked)
//     {
//         if (n < 0)
//         {
//             return 0;
//         }
//         if (n == 0)
//         {
//             if (isPicked)
//                 return 0;
//             else
//                 return nums[0];
//         }
//         if (dp[n] != -1)
//             return dp[n];
//         int sum1 = nums[n] + helper(nums, n - 2, dp, isPicked);
//         int sum2 = helper(nums, n - 1, dp, isPicked);
//         return dp[n] = max(sum1, sum2);
//     }
//     int rob(vector<int> &nums)
//     {
//         int n = nums.size();
//         if (n == 1)
//             return nums[0];
//         vector<int> dp(n, -1);
//         vector<int> dp1(n, -1);
//         return max(helper(nums, n - 1, dp, true), helper(nums, n - 2, dp1, false));
//     }
// };

//Tabulation :
// class Solution
// {
// public:
//     int helper(vector<int> &nums, int n, vector<int> &dp)
//     {

//         for (int i = 1; i <= n; i++)
//         {
//             int sum1 = nums[i];
//             if (i > 1)
//             {
//                 sum1 += dp[i - 2];
//             }
//             int sum2 = dp[i - 1];
//             dp[i] = max(sum1, sum2);
//         }
//         return dp[n];
//     }

//     int rob(vector<int> &nums)
//     {
//         int n = nums.size();
//         if (n == 1)
//             return nums[0];
//         vector<int> dp(n, -1);
//         dp[0] = 0;
//         int ans1 = helper(nums, n - 1, dp);
//         vector<int> dp1(n, -1);
//         dp1[0] = nums[0];
//         int ans2 = helper(nums, n - 2, dp1);
//         return max(ans1, ans2);
//     }
// };

// space optimised
// class Solution
// {
//     int helper(vector<int> &nums, int n, int prev, int prevprev)
//     {

//         for (int i = 1; i <= n; i++)
//         {
//             int sum1 = nums[i];
//             if (i > 1)
//             {
//                 sum1 += prevprev;
//             }
//             int sum2 = prev;
//             int cur = max(sum1, sum2);
//             prevprev = prev;
//             prev = cur;
//         }
//         return prev;
//     }

//     int rob(vector<int> &nums)
//     {
//         int n = nums.size();
//         if (n == 1)
//             return nums[0];
//         int ans1 = helper(nums, n - 1, 0, 0);
//         int ans2 = helper(nums, n - 2, nums[0], 0);
//         return max(ans1, ans2);
//     }
// };
=======
#include<bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/house-robber-ii/
//same as previous problem 
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
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp(nums.size(), -1);
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    long long int res1 = helper_SC(temp1, temp1.size());

    long long int res2 = helper_SC(temp2, temp2.size());
    return max(res1, res2);
}
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
