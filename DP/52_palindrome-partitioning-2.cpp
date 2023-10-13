#include<bits/stdc++.h>
using namespace std;

//TC : O(N*N*N)
//SC : O(N) + O(N)

bool isPalindrome(string &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
int solve(int i, string &s, vector<int> &dp)
{
    if (i == s.size())
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int mini = 1e9;
    string ds = "";
    for (int ind = i; ind < s.size(); ind++)
    {
        ds += s[ind];
        if (isPalindrome(ds))
        {
            int cuts = (ind == s.size() - 1) ? solve(ind + 1, s, dp) : 1 + solve(ind + 1, s, dp);
            mini = min(mini, cuts);
        }
    }
    return dp[i] = mini;
}
int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return solve(0, s, dp);
}

// TC : O(N*N*N)
// SC : O(N)
int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int mini = 1e9;
        string ds = "";
        for (int ind = i; ind < s.size(); ind++)
        {
            ds += s[ind];
            if (isPalindrome(ds))
            {
                int cuts = (ind == s.size() - 1) ? dp[ind + 1] : 1 + dp[ind + 1];
                mini = min(mini, cuts);
            }
        }
        dp[i] = mini;
    }
    return dp[0];
}