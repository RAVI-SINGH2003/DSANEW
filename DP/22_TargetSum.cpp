#include <bits/stdc++.h>
using namespace std;
//1. memoization
int solve(vector<int> &arr, int n, int tar, int i, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (arr[0] == 0 && tar == 0)
            return 2;
        else if (tar == 0 || arr[0] == tar)
            return 1;
        else
            return 0;
    }
    if (dp[i][tar] != -1)
        return dp[i][tar];
    int pick = 0;
    if (tar >= arr[i])
        pick = solve(arr, n, tar - arr[i], i - 1, dp);
    int notPick = solve(arr, n, tar, i - 1, dp);
    return dp[i][tar] = pick + notPick;
}
int targetSum(int n, int target, vector<int> &arr)
{
    int sum = 0;
    for (int e : arr)
        sum += e;
    int k = sum - target;
    if (k < 0 || (k & 1))
        return 0;
    int tar = (sum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return solve(arr, n, tar, n - 1, dp);
}
