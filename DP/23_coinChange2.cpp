#include <bits/stdc++.h>
using namespace std;

//1. Memoization
// TC : O(N*value)
// SC  : O(N)
#include <vector>
long count(int *arr, int n, int value, int i, vector<vector<long>> &dp)
{
    if (i == 0)
    {
        if (arr[0] == 0 && value == 0)
            return 2;
        else if (value == 0 || value % arr[0] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[i][value] != -1)
        return dp[i][value];
    long pick = 0;
    if (value >= arr[i])
        pick = count(arr, n, value - arr[i], i, dp);

    long notPick = count(arr, n, value, i - 1, dp);
    return dp[i][value] = pick + notPick;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));

    return count(denominations, n, value, n - 1, dp);
}

// 2. Tabulation

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    if (denominations[0] == 0)
        dp[0][0] = 2;
    else
    {
        dp[0][0] = 1;
        for (long val = denominations[0]; val <= value; val += denominations[0])
        {
            dp[0][val] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int val = 0; val <= value; val++)
        {
            long pick = 0;
            if (val >= denominations[i])
                pick = dp[i][val - denominations[i]];
            long notPick = dp[i - 1][val];
            dp[i][val] = pick + notPick;
        }
    }
    return dp[n - 1][value];
}

// 3 . space optimization
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> dp(value + 1, 0), temp(value + 1, 0);
    if (denominations[0] == 0)
        dp[0] = temp[0] = 2;
    else
    {
        dp[0] = temp[0] = 1;
        for (long val = denominations[0]; val <= value; val += denominations[0])
        {
            dp[val] = temp[val] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int val = 0; val <= value; val++)
        {
            long pick = 0;
            if (val >= denominations[i])
                pick = temp[val - denominations[i]];
            long notPick = dp[val];
            temp[val] = pick + notPick;
        }
        dp = temp;
    }
    return dp[value];
}