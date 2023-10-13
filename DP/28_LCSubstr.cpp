#include <bits/stdc++.h>
using namespace std;
//here dp[i][j] = length of the longest substring that ends at s[i-1] and t[j-1]
int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    string s = str1, t = str2;
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
