#include <bits/stdc++.h>
using namespace std;

//NOTE : THIS QUESTION USES THE LOGIC OF PREVIOUS QUESTION
//if we have to split the array int to two subsets such that their sums are equal means
//we just need to check if there exists a subset whose sum is equal to totalsum/2
// Recursion :
// TC  :O(2^N) + O(N) to find sum of elements
// SC : O(N)
bool helper(int idx, int k, vector<int> &arr)
{
    if (k == 0)
        return true;
    if (idx == 0)
    {
        return arr[idx] == k;
    }
    bool take = false;
    if (k >= arr[idx])
        take = helper(idx - 1, k - arr[idx], arr);
    bool notTake = helper(idx - 1, k, arr);
    return take || notTake;
}
bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    if (total & 1)
        return false;
    return helper(n - 1, total / 2, arr);
}

// Memoization :
// TC : O(N*K) + O(N) to find sum of elements
// SC : O(N) + O(N*K)
// k= sumOfAllElements/2;
bool helper(int idx, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (idx == 0)
    {
        return arr[0] == k;
    }
    if (dp[idx][k] != -1)
        return dp[idx][k];
    bool take = false;
    if (k >= arr[idx])
        take = helper(idx - 1, k - arr[idx], arr, dp);
    bool notTake = helper(idx - 1, k, arr, dp);
    return dp[idx][k] = (take || notTake);
}
bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    if (total & 1)
        return false;
    vector<vector<int>> dp(n, vector<int>(total / 2 + 1, -1));
    return helper(n - 1, total / 2, arr, dp);
}
// Tabulation :
//  TC : O(N*K) + O(N) to find sum of elements
//  SC : O(N*K)
//  k= sumOfAllElements/2;

bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    if (total & 1)
        return false;
    int k = total / 2;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool take = false;
            if (target >= arr[idx])
                take = dp[idx - 1][target - arr[idx]];
            bool notTake = dp[idx - 1][target];
            dp[idx][target] = take || notTake;
        }
    }
    return dp[n - 1][k];
}
// Space otimisation :
//  TC : O(N*K) + O(N) to find sum of elements
//  SC : O(K)
//  k= sumOfAllElements/2;
bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    if (total & 1)
        return false;
    int k = total / 2;
    vector<bool> prev(k + 1, false);
    vector<bool> cur(k + 1, false);

    prev[0] = cur[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;
    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool take = false;
            if (target >= arr[idx])
                take = prev[target - arr[idx]];
            bool notTake = prev[target];
            cur[target] = take || notTake;
        }
        prev = cur;
    }
    return prev[k];
}

//=----------------------------------------------------------------------------------------
//note : here we used the code of dp-14
//in tabulation method we created a matrix dp[0-----n-1][0------k]
//the last row of matrix gives if if have array from 0 to n-1 index
//can target of 0 ,1 ,2,3,4,5,6,7,...........k id possible or not

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    int k = total;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool take = false;
            if (target >= arr[idx])
                take = dp[idx - 1][target - arr[idx]];
            bool notTake = dp[idx - 1][target];
            dp[idx][target] = take || notTake;
        }
    }
    //     dp[n-1][0.....k]
    int mini = 1e9;
    for (int s1 = 0; s1 <= k / 2; s1++)
    {
        if (dp[n - 1][s1])
        {
            int sum1 = s1;
            int sum2 = total - s1;
            mini = min(mini, abs(sum1 - sum2));
        }
    }
    return mini;
}
