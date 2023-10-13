<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

//NOTE : THIS QUESTION IS HAVING VARIABLE STARTING AND ENDING POINTS

// Recursion :
// TC : O(M*3^N) 3^N and not 3^(N*N) because from every cell always move down to same col or left or right diagonal column so i will traverse only N cells 1 cell in each row
// SC : O(path length) = O(N)
int helper(vector<vector<int>> &matrix, int i, int j, int m)
{
    if (i < 0 || j < 0 || j >= m)
        return -1000000;
    if (i == 0)
        return matrix[i][j];
    int up = helper(matrix, i - 1, j, m) + matrix[i][j];
    int left = helper(matrix, i - 1, j - 1, m) + matrix[i][j];
    int right = helper(matrix, i - 1, j + 1, m) + matrix[i][j];
    return max(up, max(left, right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, helper(matrix, n - 1, i, m));
    }
    return maxi;
}

//Memoization : 
//TC : O(M*M*N)
//SC :  O(N) + O(N*M)
int helper(vector<vector<int>> &matrix, int i, int j, int m, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0 || j >= m)
        return -1000000;
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];
    int up = helper(matrix, i - 1, j, m, dp) + matrix[i][j];
    int left = helper(matrix, i - 1, j - 1, m, dp) + matrix[i][j];
    int right = helper(matrix, i - 1, j + 1, m, dp) + matrix[i][j];
    return dp[i][j] = max(up, max(left, right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, helper(matrix, n - 1, i, m, dp));
    }
    return maxi;
}
//Tabulation :
//TC  : O(N*M) +O(M)
//SC : O(N*M)
int helper(vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
{
    // Initializing first row - base condition
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j], left = matrix[i][j], right = matrix[i][j];
            if (i - 1 >= 0)
                up += dp[i - 1][j];
            else
                up = -1000000;
            if (i - 1 >= 0 && j - 1 >= 0)
                left += dp[i - 1][j - 1];
            else
                left = -1000000;
            if (i - 1 >= 0 && j + 1 < m)
                right += dp[i - 1][j + 1];
            else
                right = -1000000;
            dp[i][j] = max(up, max(left, right));
        }
    }
    int maxi = INT_MIN;
    //     because during recursion calls were made for helper(n-1,0) ,helper(n-1,1)......helper(n-1,m-1) so we have to take max of all calls
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, dp[n - 1][i]);
    }
    return maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(matrix, n, m, dp);
}

//SO :
//TC: O(N*M) +O(M) 
// SC: O(M)

int helper(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> prev(m, -1);
    // initialising base case
    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];
    for (int i = 1; i < n; i++)
    {
        vector<int> cur(m, -1);
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
                cur[j] = matrix[i][j];
            else
            {
                int up = matrix[i][j], left = matrix[i][j], right = matrix[i][j];
                if (i - 1 >= 0)
                    up += prev[j];
                else
                    up = -1000000;
                if (i - 1 >= 0 && j - 1 >= 0)
                    left += prev[j - 1];
                else
                    left = -1000000;
                if (i - 1 >= 0 && j + 1 < m)
                    right += prev[j + 1];
                else
                    right = -1000000;
                cur[j] = max(up, max(left, right));
            }
        }
        prev = cur;
    }
    int maxi = INT_MIN;
    //  because during recursion calls were made for helper(n-1,0) ,helper(n-1,1)......helper(n-1,m-1) so we have to take max of all calls
    for (int i = 0; i < m; i++)
    {
        maxi = max(prev[i], maxi);
    }
    return maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    return helper(matrix, n, m);
}

=======
#include <bits/stdc++.h>
using namespace std;

//NOTE : THIS QUESTION IS HAVING VARIABLE STARTING AND ENDING POINTS

// Recursion :
// TC : O(M*3^N) 3^N and not 3^(N*N) because from every cell always move down to same col or left or right diagonal column so i will traverse only N cells 1 cell in each row
// SC : O(path length) = O(N)
int helper(vector<vector<int>> &matrix, int i, int j, int m)
{
    if (i < 0 || j < 0 || j >= m)
        return -1000000;
    if (i == 0)
        return matrix[i][j];
    int up = helper(matrix, i - 1, j, m) + matrix[i][j];
    int left = helper(matrix, i - 1, j - 1, m) + matrix[i][j];
    int right = helper(matrix, i - 1, j + 1, m) + matrix[i][j];
    return max(up, max(left, right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, helper(matrix, n - 1, i, m));
    }
    return maxi;
}

//Memoization : 
//TC : O(M*M*N)
//SC :  O(N) + O(N*M)
int helper(vector<vector<int>> &matrix, int i, int j, int m, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0 || j >= m)
        return -1000000;
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];
    int up = helper(matrix, i - 1, j, m, dp) + matrix[i][j];
    int left = helper(matrix, i - 1, j - 1, m, dp) + matrix[i][j];
    int right = helper(matrix, i - 1, j + 1, m, dp) + matrix[i][j];
    return dp[i][j] = max(up, max(left, right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, helper(matrix, n - 1, i, m, dp));
    }
    return maxi;
}
//Tabulation :
//TC  : O(N*M) +O(M)
//SC : O(N*M)
int helper(vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
{
    // Initializing first row - base condition
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j], left = matrix[i][j], right = matrix[i][j];
            if (i - 1 >= 0)
                up += dp[i - 1][j];
            else
                up = -1000000;
            if (i - 1 >= 0 && j - 1 >= 0)
                left += dp[i - 1][j - 1];
            else
                left = -1000000;
            if (i - 1 >= 0 && j + 1 < m)
                right += dp[i - 1][j + 1];
            else
                right = -1000000;
            dp[i][j] = max(up, max(left, right));
        }
    }
    int maxi = INT_MIN;
    //     because during recursion calls were made for helper(n-1,0) ,helper(n-1,1)......helper(n-1,m-1) so we have to take max of all calls
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, dp[n - 1][i]);
    }
    return maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(matrix, n, m, dp);
}

//SO :
//TC: O(N*M) +O(M) 
// SC: O(M)

int helper(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> prev(m, -1);
    // initialising base case
    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];
    for (int i = 1; i < n; i++)
    {
        vector<int> cur(m, -1);
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
                cur[j] = matrix[i][j];
            else
            {
                int up = matrix[i][j], left = matrix[i][j], right = matrix[i][j];
                if (i - 1 >= 0)
                    up += prev[j];
                else
                    up = -1000000;
                if (i - 1 >= 0 && j - 1 >= 0)
                    left += prev[j - 1];
                else
                    left = -1000000;
                if (i - 1 >= 0 && j + 1 < m)
                    right += prev[j + 1];
                else
                    right = -1000000;
                cur[j] = max(up, max(left, right));
            }
        }
        prev = cur;
    }
    int maxi = INT_MIN;
    //  because during recursion calls were made for helper(n-1,0) ,helper(n-1,1)......helper(n-1,m-1) so we have to take max of all calls
    for (int i = 0; i < m; i++)
    {
        maxi = max(prev[i], maxi);
    }
    return maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    return helper(matrix, n, m);
}

>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
