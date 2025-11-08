#include <bits/stdc++.h>
using namespace std;
//NOTE : THIS QUESTION IS HAVING FIXED STARTING POINT BUT VARIABLE ENDING POINT

// Recursion :

// start from 0 row and go to row 0 n-1
// TC : O(2^N*N)
// SC : O(N)

int helper(vector<vector<int>> &triangle, int i, int j, int n)
{

    if (i >= n || j >= n)
        return 1e9;
    if (i == n - 1)
        return triangle[i][j];

    int up = helper(triangle, i + 1, j, n) + triangle[i][j];
    int left = helper(triangle, i + 1, j + 1, n) + triangle[i][j];
    return min(up, left);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    return helper(triangle, 0, 0, n);

}

// Memoization :

//  start from 0 row and go to row 0 n-1
// TC : O(N*N)
// SC : O(N) + O(N*N)

int helper(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp)
{

    if (i >= n || j >= n)
        return 1e9;
    if (i == n - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = helper(triangle, i + 1, j, n, dp) + triangle[i][j];
    int left = helper(triangle, i + 1, j + 1, n, dp) + triangle[i][j];
    return dp[i][j] = min(up, left);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(triangle, 0, 0, n, dp);
}

// Tabulation :
//start from 0 row and go to row n-1
//TC : O(N*N)
//SC : O(N*N)

int helper(vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    // initialising base case
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j>=0; j--)
        {
            int up = dp[i + 1][j] + triangle[i][j];
            int left = dp[i + 1][j + 1] + triangle[i][j];
            dp[i][j] = min(up, left);
        }
    }
    // recursive call was made for helper[0][0];
    return dp[0][0];
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(triangle, n, dp);
}

//Space Optimisation
//TC : O(N*N)
//SC :O(N)
int helper(vector<vector<int>> &triangle, int i, int j, int n)
{
    vector<int> prev(n, -1);

    // initialising base case
    for (int j = 0; j < n; j++)
        prev[j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> cur(n, -1);
        for (int j = i; j >= 0; j--)
        {
          
         
                int up = prev[j] + triangle[i][j];
                int left = prev[j + 1] + triangle[i][j];
                cur[j] = min(up, left);
        }
        prev = cur;
    }
    // recursive call was made for helper[0][0];
    return prev[0];
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    return helper(triangle, 0, 0, n);
}