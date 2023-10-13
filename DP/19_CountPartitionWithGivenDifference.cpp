#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int fun(vector<int> &arr, int k, int idx, vector<vector<int>> &dp)
{
    if (k < 0)
        return 0;
    if (idx == 0)
    {
        if (k == 0 && arr[0] == 0)
            return 2;
        else if (k == 0)
            return 1;
        else
            return k == arr[0];
    }
    if (dp[idx][k] != -1)
        return dp[idx][k];

    int pick = fun(arr, k - arr[idx], idx - 1, dp);
    int notPick = fun(arr, k, idx - 1, dp);
    return dp[idx][k] = (pick + notPick) % N;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if ((sum + d) & 1)
        return 0;
    int k = (sum + d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return fun(arr, k, n - 1, dp);
}