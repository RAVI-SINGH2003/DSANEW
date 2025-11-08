#include <bits/stdc++.h> 
using namespace std;

//TC : O(2^N*M)
//SC : O(path_length) =O(N-1 +  M-1)
int helper_R(vector<vector<int>> &grid, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
        return 1e9; //not returning INT_MAX because on addition it will overflow
  
    int up = helper_R(grid, i - 1, j) + grid[i][j];
    int left = helper_R(grid, i, j - 1) + grid[i][j];

    return min(up, left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n  = grid.size();
    int m =grid[0].size();
   return helper_R(grid,n-1,m-1);
}

// TC : O(N*M)
// SC : O(path_length) + O(dp.size)=O(N-1 +  M-1) + O(N*M)

#include <bits/stdc++.h>
int helper_M(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];
   
  
        int up = helper_M(grid, i - 1, j, dp) + grid[i][j];
   
        int left = helper_M(grid, i, j - 1, dp) + grid[i][j];

    return dp[i][j] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper_M(grid, n - 1, m - 1, dp);
}

// TC : O(N*M)
// SC : O(N*M)
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = grid[0][0]; // continue;
            else
            {
                    int up = grid[i][j],left = grid[i][j];
                    if(i-1>=0)
                      up+= dp[i - 1][j];
                    else
                       up = INT_MAX; //or any big number like 1e9
                    if(j-1>=0)
                       left += dp[i][j - 1];
                    else
                        left = INT_MAX; // or any big number like 1e9

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}

// TC : O(N*M)
// SC : O(M)

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0); // we can initialse wih -1 also

    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                cur[0] = grid[0][0]; // continue;
            else
            {
                int up = grid[i][j], left = grid[i][j];
                if (i - 1 >= 0)
                    up +=prev[j];
                else
                    up = INT_MAX; // or any big number like 1e9
                if (j - 1 >= 0)
                    left += cur[j - 1];
                else
                    left = INT_MAX; // or any big number like 1e9

                cur[j] = min(up, left);
            }
        }
        prev = cur;
    }

    return prev[m - 1];
}