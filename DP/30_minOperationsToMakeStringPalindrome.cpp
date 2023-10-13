#include<bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>
int minimumInsertions(string &str)
{
    int n = str.size();
    string t = str;
    reverse(t.begin(), t.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    int minOp = n - dp[n][n];
    return minOp;
}
