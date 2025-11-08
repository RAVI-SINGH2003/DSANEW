#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
// TC :O(2^M*N)
// SC : O(path length) = O(M-1+N-1)
 int helper_R(int i, int j, int m, int n)
 {
     if (i == 0 && j == 0)
         return 1;
     if (i < 0 || j < 0)
         return 0;
     int left = helper_R(i, j - 1, m, n);
     int up = helper_R(i - 1, j, m, n);
     return (left + up);
 }
 int uniquePaths(int m, int n)    
 {
     return helper_R(m - 1, n - 1, m, n);
 }

 // TC :O(M*N)
 // SC : O(path length) = O(M-1+N-1)  + O(M*N)

 int helper_M(int i, int j, int m, int n, vector<vector<int>> &dp)
 {
     if (i == 0 && j == 0)
         return 1;
     if (i < 0 || j < 0)
         return 0;
     if (dp[i][j] != -1)
         return dp[i][j];
     int left = helper_M(i, j - 1, m, n, dp);
     int up = helper_M(i - 1, j, m, n, dp);
     return dp[i][j] = (left + up);
 }
 int uniquePaths(int m, int n)
 {
     vector<vector<int>> dp(m, vector<int>(n, -1));
     return helper_M(m - 1, n - 1, m, n, dp);
 }

 // TC :O(M*N)
 // SC : O(path length) = O(M*N)  

 int helper_T(int m, int n, vector<vector<int>> &dp)
 {
     dp[0][0] = 1;
     for (int i = 0; i < m; i++)
     {
         for (int j = 0; j < n; j++)
         {
             if (i == 0 && j == 0)
                 dp[i][j] = 1;
             else
             {
                 int left = 0, up = 0;
                 if (j - 1 >= 0)
                     left += dp[i][j - 1];
                 if (i - 1 >= 0)
                     up += dp[i - 1][j];
                 dp[i][j] = left + up;
             }
         }
     }
     return dp[m - 1][n - 1];
 }
 int uniquePaths(int m, int  n)
 {
     vector<vector<int>> dp(m, vector<int>(n, -1));
     return helper_T(m, n, dp);
}

 //TC : O(m*n)
 //sc : O(N)

 int helper_SO(int m, int n)
 {
   
     vector<int> prev1(n, 0);
     for (int i = 0; i < m; i++)
     {
         vector<int> cur(n, 0);
         for (int j = 0; j < n; j++)
         {
             if (i == 0 && j == 0)
                 cur[j] = 1;
             else
             {
                 int left = 0, up = 0;  
                 if (j - 1 >= 0)
                     left += cur[j - 1];
                 if (i - 1 >= 0)
                     up += prev1[j];
                 cur[j] = left + up;
             }
         }
         prev1 = cur;
     }
     return prev1[n - 1];
 }
 int uniquePaths(int m, int n)
 {
    
     return helper_SO(m, n);
 }