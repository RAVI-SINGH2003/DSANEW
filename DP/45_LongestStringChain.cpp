#include<bits/stdc++.h>
using namespace  std;

// TC : O(N^2 * L) L = avg length of strings
//SC : O(N)

bool checkPredecessor(string word, string pre)
{
    int i = 0, j = 0;
    int n = word.size(), m = pre.size();
    if (n - m != 1)
        return false;
    while (i < n && j < m)
    {
        if (word[i] == pre[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (i == n && j == m || j == m)
        return true;
    return false;
}
static bool comp(string a, string b)
{
    return a.size() < b.size();
}
int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), comp);
    int n = words.size();
    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {

            if (checkPredecessor(words[i], words[prev]) && (1 + dp[prev] > dp[i]))
            {
                dp[i] = 1 + dp[prev];
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }
    return ans;
}