#include <bits/stdc++.h>
using namespace std;

// We sort the array in increasing order of width.And if two widths are same, we need to sort height in decreasing order.Now why we need to sort in decreasing order if two widths are same.By this practice, we 're assuring that no width will get counted more than one time.

// TC : O(NLogN)
static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] < b[0])
        return true;
    else if (a[0] == b[0])
        return a[1] > b[1];
    else
        return false;
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    // sort according to wisth or heigth
    sort(envelopes.begin(), envelopes.end(), comp);
    vector<int> dp;
    dp.push_back(envelopes[0][1]);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (envelopes[i][1] > dp.back())
        {
            dp.push_back(envelopes[i][1]);
        }
        else
        {
            int idx = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
            dp[idx] = envelopes[i][1];
        }
    }
    return dp.size();
}

// TC : O(N^2)

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    // sort according to wisth or heigth
    sort(envelopes.begin(), envelopes.end());
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (envelopes[prev][0] < envelopes[i][0] && envelopes[prev][1] < envelopes[i][1])
                dp[i] = max(1 + dp[prev], dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}