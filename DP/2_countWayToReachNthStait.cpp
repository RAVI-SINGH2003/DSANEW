<<<<<<< HEAD
// https: // www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
using namespace std;
int N = 1e9 + 7;

//recursion : 
// Tc: O(2^N);
//SC  : O(N)
int countDistinctWays(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int twoJump = countDistinctWays(n - 2);
    int oneJump = countDistinctWays(n - 1);
    return (twoJump + oneJump) % N;
}
//memoization
//TC: O(N)
//SC:O(N) +O(N) = for the dp vector
int helper(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int twoJump = helper(n - 2, dp);
    int oneJump = helper(n - 1, dp);
    return dp[n] = (twoJump + oneJump) % N;
}
int countDistinctWays(int n)
{
    vector<int> dp(n + 1, -1);
    return helper(n, dp);
}

// tabulation
// TC: O(N)
// SC :O(N)
int countDistinctWays(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % N;
    }
    return dp[n];
}

//Space optimization
//TC: O(N)
//SC : O(1)
int countDistinctWays(int n)
{
    // vector<int> dp(n+1,-1);
    int prev1 = 1;
    int prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = (prev1 + prev2) % N;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
=======
// https: // www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
using namespace std;
int N = 1e9 + 7;

//recursion : 
// Tc: O(2^N);
//SC  : O(N)
int countDistinctWays(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int twoJump = countDistinctWays(n - 2);
    int oneJump = countDistinctWays(n - 1);
    return (twoJump + oneJump) % N;
}
//memoization
//TC: O(N)
//SC:O(N) +O(N) = for the dp vector
int helper(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int twoJump = helper(n - 2, dp);
    int oneJump = helper(n - 1, dp);
    return dp[n] = (twoJump + oneJump) % N;
}
int countDistinctWays(int n)
{
    vector<int> dp(n + 1, -1);
    return helper(n, dp);
}

// tabulation
// TC: O(N)
// SC :O(N)
int countDistinctWays(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % N;
    }
    return dp[n];
}

//Space optimization
//TC: O(N)
//SC : O(1)
int countDistinctWays(int n)
{
    // vector<int> dp(n+1,-1);
    int prev1 = 1;
    int prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = (prev1 + prev2) % N;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
