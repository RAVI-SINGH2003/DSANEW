#include<bits/stdc++.h>
using namespace std;
int N = 1e9 + 7;

//TC : O(2^N*M)
//sc : O(M-1 + N-1)
int helper(int n, int m, int i, int j, vector<vector<int>> &mat)
{
   
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = 0, left = 0;
    if (i - 1 >= 0 && mat[i - 1][j] != -1)
        up = helper(n, m, i - 1, j, mat);
    if (j - 1 >= 0 && mat[i][j - 1] != -1)
        left = helper(n, m, i, j - 1, mat);
    return (up + left) % N;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    return helper(n, m, n - 1, m - 1, mat);
}

//TC :O(M*N)
//sc : O(M-1 + N-1) + O(N*M)
int N = 1e9 + 7;
int helper_M(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{

    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = 0, left = 0;
    if (i - 1 >= 0 && mat[i - 1][j] != -1)
        up = helper_M(i - 1, j, mat, dp);
    if (j - 1 >= 0 && mat[i][j - 1] != -1)
        left = helper_M(i, j - 1, mat, dp);
    return dp[i][j] = (up + left) % N;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper_M(n - 1, m - 1, mat, dp);
}

//TC : O(N*M)
//SC :  O(N*M)
int N = 1e9 + 7;
int helper_T(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else
            {
                int up = 0, left = 0;
                if (i - 1 >= 0 && mat[i - 1][j] != -1)
                    up = dp[i - 1][j];
                if (j - 1 >= 0 && mat[i][j - 1] != -1)
                    left = dp[i][j - 1];
                dp[i][j] = (up + left) % N;
            }
        }
    }
    return dp[n - 1][m - 1];
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper_T(n, m, mat, dp);
}

//TC : O(N*M)
//SC : O(M);

int helper(int n, int m, vector<vector<int>> &mat)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                cur[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i - 1 >= 0 && mat[i - 1][j] != -1)
                    up = prev[j];
                if (j - 1 >= 0 && mat[i][j - 1] != -1)
                    left = cur[j - 1];
                cur[j] = (up + left) % N;
            }
        }

        prev = cur;
    }
    return prev[m - 1];
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{

    return helper(n, m, mat);
}