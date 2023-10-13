<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
//recursion: 
//TC: O(2^N)
//SC :O(N)
bool helper(int idx, int k, vector<int> &arr)
{
    if (k == 0)
        return true;
    if (idx == 0)
    {
        return arr[idx] == k;
    }
    bool take = false;
    if(k>=arr[idx])
      take = helper(idx-1,k-arr[idx],arr);
    bool notTake= helper(idx-1,k,arr);
    return take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return helper(n - 1, k, arr);
}

//Memoization : 
//TC : O(N*K);
//SC : O(N) + O(N*K)
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
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return helper(n - 1, k, arr, dp);
}

//Tabulation
//TC :O(N*K)
//TC :O(N*K)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

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
//Space optimization
//TC :O(N*K)
//SC : O(K);
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false);
    vector<bool> cur(k + 1, false);

    prev[0] = cur[0] = true;
    if(arr[0]<=k)
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

//space optimised:
//tc : O(n*totalsum)
//sc : O(TotalSum)
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    int k = total;
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

    //     dp[n-1][0.....k]
    int mini = 1e9;
    for (int s1 = 0; s1 <= k / 2; s1++)
    {
        if (prev[s1])
        {
            int sum1 = s1;
            int sum2 = total - s1;
            mini = min(mini, abs(sum1 - sum2));
        }
    }
    return mini;
}
=======
#include <bits/stdc++.h>
using namespace std;
//recursion: 
//TC: O(2^N)
//SC :O(N)
bool helper(int idx, int k, vector<int> &arr)
{
    if (k == 0)
        return true;
    if (idx == 0)
    {
        return arr[idx] == k;
    }
    bool take = false;
    if(k>=arr[idx])
      take = helper(idx-1,k-arr[idx],arr);
    bool notTake= helper(idx-1,k,arr);
    return take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return helper(n - 1, k, arr);
}

//Memoization : 
//TC : O(N*K);
//SC : O(N) + O(N*K)
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
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return helper(n - 1, k, arr, dp);
}

//Tabulation
//TC :O(N*K)
//TC :O(N*K)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

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
//Space optimization
//TC :O(N*K)
//SC : O(K);
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false);
    vector<bool> cur(k + 1, false);

    prev[0] = cur[0] = true;
    if(arr[0]<=k)
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

//space optimised:
//tc : O(n*totalsum)
//sc : O(TotalSum)
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    int k = total;
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

    //     dp[n-1][0.....k]
    int mini = 1e9;
    for (int s1 = 0; s1 <= k / 2; s1++)
    {
        if (prev[s1])
        {
            int sum1 = s1;
            int sum2 = total - s1;
            mini = min(mini, abs(sum1 - sum2));
        }
    }
    return mini;
}
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
