#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = arr[i - 1] * arr[k] * arr[j] + solve(arr, i, k, dp) + solve(arr, k + 1, j, dp);
        mini = min(mini, temp);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(arr, 1, N - 1, dp);
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (i == j)
                continue;
            int mini = 1e9;
            for (int k = i; k <= j - 1; k++)
            {
                int temp = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, temp);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}