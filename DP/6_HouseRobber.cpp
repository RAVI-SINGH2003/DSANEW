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
