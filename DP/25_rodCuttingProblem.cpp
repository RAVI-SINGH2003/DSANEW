#include <bits/stdc++.h>
using namespace std;

// 1.Memoization
int solve(vector<int> &price, int cutSize, int len, vector<vector<int>> &dp)
{
    if (cutSize == 1)
    {
        // trying cut of size 1
        //if rod len already zero profit = 0;
        if (len == 0)
            return 0;
        else
            return price[0] * len;
    }
    if (dp[cutSize][len] != -1)
        return dp[cutSize][len];
    int pick = 0;
    if (len >= cutSize)
        pick = price[cutSize - 1] + solve(price, cutSize, len - cutSize, dp);
    int notPick = solve(price, cutSize - 1, len, dp);
    return dp[cutSize][len] = max(pick, notPick);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return solve(price, n, n, dp);
}

// 2. Tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[1][0] = 0;

    for (int l = 1; l <= n; l++)
    {
        dp[1][l] = price[0] * l;
    }

    for (int cutSize = 2; cutSize <= n; cutSize++)
    {
        for (int len = 0; len <= n; len++)
 
            int pick = 0;
            if (len >= cutSize)
                pick = price[cutSize - 1] + dp[cutSize][len - cutSize];
            int notPick = dp[cutSize - 1][len];
            dp[cutSize][len] = max(pick, notPick);
        }
    }
    return dp[n][n];
}

// 3. Space Optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    prev[0] = 0;

    for (int l = 1; l <= n; l++)
    {
        prev[l] = price[0] * l;
    }

    for (int cutSize = 2; cutSize <= n; cutSize++)
    {
        for (int len = 0; len <= n; len++)
        {
            int pick = 0;
            if (len >= cutSize)
                pick = price[cutSize - 1] + curr[len - cutSize];
            int notPick = prev[len];
            curr[len] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[n];
}

// 4. single array optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int l = 1; l <= n; l++)
    {
        dp[l] = price[0] * l;
    }

    for (int cutSize = 2; cutSize <= n; cutSize++)
    {
        for (int len = 0; len <= n; len++)
        {
            int pick = 0;
            if (len >= cutSize)
                pick = price[cutSize - 1] + dp[len - cutSize];
            int notPick = dp[len];
            dp[len] = max(pick, notPick);
        }
    }
    return dp[n];
}
