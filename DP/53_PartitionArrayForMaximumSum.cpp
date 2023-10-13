#include <bits/stdc++.h>
using namespace std;

//TC : O(N*k)
//SC : O(N) + O(N)
int solve(int i, vector<int> &arr, int k, vector<int> &dp)
{
    if (i == arr.size())
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int maxi = -1e9;
    int maxe = arr[i];
    for (int ind = i; ind < i + k && ind < arr.size(); ind++)
    {
        maxe = max(maxe, arr[ind]);
        int sum = (ind - i + 1) * maxe + solve(ind + 1, arr, k, dp);
        maxi = max(maxi, sum);
    }
    return dp[i] = maxi;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, arr, k, dp);
}

//TC : O(N*K)
//SC : O(N)
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int maxi = -1e9;
        int maxe = arr[i];
        for (int ind = i; ind < i + k && ind < arr.size(); ind++)
        {
            maxe = max(maxe, arr[ind]);
            int sum = (ind - i + 1) * maxe + dp[ind + 1];
            maxi = max(maxi, sum);
        }
        dp[i] = maxi;
    }

    return dp[0];
}