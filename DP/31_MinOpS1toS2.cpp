#include<bits/stdc++.h>
using namespace std;
int canYouMake(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int N = 0; N < n + 1; N++)
    {
        dp[N][0] = 0;
    }
    for (int M = 0; M < m + 1; M++)
    {
        dp[0][M] = 0;
    }
    for (int idx1 = 1; idx1 < n + 1; idx1++)
    {
        for (int idx2 = 1; idx2 < m + 1; idx2++)
        {
            // match
            if (s1[idx1 - 1] == s2[idx2 - 1])
            {
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            }
            // not match
            else
            {
                int op1 = dp[idx1 - 1][idx2];
                int op2 = dp[idx1][idx2 - 1];
                dp[idx1][idx2] = max(op1, op2);
            }
        }
    }
    int lcs = dp[n][m];
    int s1NonLcsLength = n - lcs;
    int s2NonLcsLength = m - lcs;
    int changeInLength = abs(s1NonLcsLength - s2NonLcsLength);       // change in length shows direct addition or deletion og elements
    int replaceOperations = min(s1NonLcsLength, s2NonLcsLength) * 2; // remaining characters are replaced which is addition + deletion for one char so 2 op for 1 char
    int minOp = changeInLength + replaceOperations;                  // no of direct addition/deletions + replace operations
    return minOp;
}

//Approach - 2

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
    return dp[i][j] = min(op1, op2);
}
int minOperations(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    return solve(n - 1, m - 1, str1, str2, dp);
}