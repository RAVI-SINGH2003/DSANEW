#include<bits/stdc++.h>
using namespace std;
//TC : O(n*m)
//SC : O(n*m)
//Approach = we keep track of how many squares end at a r,c
int countSquares(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int c = 0; c < m; c++)
        dp[0][c] = matrix[0][c];
    for (int r = 0; r < n; r++)
        dp[r][0] = matrix[r][0];

    for (int r = 1; r < n; r++)
    {
        for (int c = 1; c < m; c++)
        {
            //if element itself is zero then no square can end on this
            if (matrix[r][c] == 0)
                dp[r][c] = 0;
            else
                dp[r][c] = 1 + min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]});
        }
    }

    int count = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            count += dp[r][c];
        }
    }
    return count;
}