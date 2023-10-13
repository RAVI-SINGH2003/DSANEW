#include<bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int> &nums)
{

    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1), parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int lastIndex = 0;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {

            if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                parent[i] = prev;
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }
    }
    int k = lastIndex;
    vector<int> subset;
    while (k != parent[k])
    {
        subset.push_back(nums[k]);
        k = parent[k];
    }
    subset.push_back(nums[k]);
    reverse(subset.begin(), subset.end());
    return subset;
}