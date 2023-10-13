#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> ways(n, 0);
        ways[0] = 1;
        int count = 0;
        int lis_length = 1;
        for (int i = 1; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            //dp[i] = length of lis which ends at nums[i]
            //so i am figuring out which prev element to i form  lis of length dp[i] or are a part of lis of lenght dp[i]
            // so no of ways of achieving lis length of dp[i] = no of ways of ahieving lis of lenght dp[i] - 1;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i])
                {
                    ways[i] += ways[prev];
                }
            }
            if (ways[i] == 0)
                ways[i] = 1;
            if (lis_length < dp[i])
            {
                lis_length = dp[i];
            }
        }

        // there can be multiple lis 
        // so we have to add all ways of achieving lis
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == lis_length)
            {
                ans += ways[i];
            }
        }
        return ans;
    }
};