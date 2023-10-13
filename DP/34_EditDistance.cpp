#include <bits/stdc++.h>
using namespace std;

// 1. Memoizaition
//TC : O(N*M) 
//SC : O(N*M) + O(N+M)
int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp)
{
    // word1=="" && word2==""
    if (i < 0 && j < 0)
        return 0;
    // word1=="" && word2!=""
    if (i < 0 && j >= 0)
        return j + 1;

    // word1!="" && word2==""
    if (i >= 0 && j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    // if match now no need of insert delete or replace
    // i will now try to find minimum no of operations required to convert
    // word1[0....i-1] to word2[0.....j-1]
    if (word1[i] == word2[j])
        return solve(i - 1, j - 1, word1, word2, dp);

    // 1. insert operation for example
    // word1 = horse i at e
    // word2 = ros j at s
    // i will insert s at pos i+1 (that's why +1) and match word1[i+1] with word2[j]
    // then try to match word1[0...i] with word2[0....j-1] that is horse with ro
    int op1 = 1 + solve(i, j - 1, word1, word2, dp);

    // 2.delete operation for example
    // word1 = horse i at e
    // word2 = ros j at s
    // i will try to delete e at pos i (that's why +1)
    // then try to match remaining word1[0...i-1] with word2[0......j] that is hors with ros
    int op2 = 1 + solve(i - 1, j, word1, word2, dp);

    // 3. replace operation for example
    // word1 = horse i at e
    // word2 = ros j at s
    // i will try to replace e at pos i (that's why +1) with s
    // then try to match remaining word1[0...i-1] with word2[0......j-1] that is hors with ro
    int op3 = 1 + solve(i - 1, j - 1, word1, word2, dp);

    return dp[i][j] = min(op1, min(op2, op3));
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    return solve(n - 1, m - 1, word1, word2, dp);
}


//2. Tabulation
//TC : O(N*M)
//Sc : O(N*M)

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp state = min op to convert string word1[0....n-1] to word2[0...j-1]

    // to handle negative case we will use one based indexing
    // so <0 will be ==0

    // word1 == "" && word2==""
    dp[0][0] = 0;
    // word1 = "" and word2!=""
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = j;
    }
    // word1 !="" and word2==""
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // match
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // not match
            else
            {
                int op1 = 1 + dp[i][j - 1];
                int op2 = 1 + dp[i - 1][j];
                int op3 = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(op1, min(op2, op3));
            }
        }
    }
    return dp[n][m];
}


//3. SPace optimization

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    prev[0] = 0;
    for (int j = 1; j <= m; j++)
    {
        prev[j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        // important
        cur[0] = i;
        for (int j = 1; j <= m; j++)
        {
            // match
            if (word1[i - 1] == word2[j - 1])
                cur[j] = prev[j - 1];

            // not match
            else
            {
                int op1 = 1 + cur[j - 1];
                int op2 = 1 + prev[j];
                int op3 = 1 + prev[j - 1];
                cur[j] = min(op1, min(op2, op3));
            }
        }
        prev = cur;
    }
    return prev[m];
}