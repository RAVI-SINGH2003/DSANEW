#include<bits/stdc++.h>
using namespace std;

//NOTE : WELCOME TO 3D DP 

//Recursion : 
//TC :O(3^R*3^R) for alice and bob we have three choices and they will travel the no of rows
//SC : O(path length) = O(R) as alice and bob can move only doen and that will be the maximum path length

int helper(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{

    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
        return -1e9;
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return (grid[i][j1] + grid[i][j2]);
    }

    int maxi = INT_MIN;
    // explore all paths of alice and bob simultaneoulsy
    for (int J1 = -1; J1 <= 1; J1++)
    {
        for (int J2 = -1; J2 <= 1; J2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j2];
            else
                value = grid[i][j1] + grid[i][j2];
            maxi = max(maxi, helper(i + 1, j1 + J1, j2 + J2, r, c, grid) + value);
        }
    }

    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{

    return helper(0, 0, c - 1, r, c, grid);
}
// Memoization :
// TC :O(R*C*C)*9
// SC : O(path length) = O(R*C*C) + O(R) as alice and bob can move only doen and that will be the maximum path length
int helper(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{

    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
        return -1e9;
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return (grid[i][j1] + grid[i][j2]);
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = INT_MIN;
    // explore all paths of alice and bob simultaneoulsy
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j2];
            else
                value = grid[i][j1] + grid[i][j2];
              value += helper(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
              maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // int dp[for i][for j1][for j2]
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return helper(0, 0, c - 1, r, c, grid, dp);
}

//Tabulation :
//TC : O(R*C*C)*9
//SC : O(R*C*C)
int helper(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{

    for (int j1 = c - 1; j1 >= 0; j1--)
    {
        for (int j2 = c - 1; j2 >= 0; j2--)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    // Outer Nested Loops for travering DP Array
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = c - 1; j1 >= 0; j1--)
        {
            for (int j2 = c - 1; j2 >= 0; j2--)
            {

                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {

                        int ans = 0;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= c) ||
                            (j2 + dj < 0 || j2 + dj >= c))

                            ans += -1e9;
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj];

                        maxi = max(ans, maxi);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c - 1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // int dp[r][r][c]
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return helper(0, 0, c - 1, r, c, grid, dp);
}

// Space optimization : 
//  1d dp optimised to 2 variables used
// 2d dp optimised to 1d dp
// 3d optimised to 2d dp
//SC : O(R*C*C)*9
//SC : O(C*C)

int helper(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> front(c, vector<int>(c, -1));
    for (int j1 = c - 1; j1 >= 0; j1--)
    {
        for (int j2 = c - 1; j2 >= 0; j2--)
        {
            if (j1 == j2)
                front[j1][j2] = grid[r - 1][j1];
            else
                front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    // Outer Nested Loops for travering DP Array
    for (int i = r - 2; i >= 0; i--)
    {
        vector<vector<int>> cur(c, vector<int>(c, -1));
        for (int j1 = c - 1; j1 >= 0; j1--)
        {
            for (int j2 = c - 1; j2 >= 0; j2--)
            {

                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int ans = 0;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= c) ||
                            (j2 + dj < 0 || j2 + dj >= c))

                            ans += -1e9;
                        else
                            ans += front[j1 + di][j2 + dj];

                        maxi = max(ans, maxi);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }

    return front[0][c - 1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{

    return helper(r, c, grid);
}