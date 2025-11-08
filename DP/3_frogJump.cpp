#include <bits/stdc++.h>
using namespace std;

//NOTE : -WE HAVE CHANGFED PROBLEM TO 0 BASE INDEXING
// SO WE WILL NOW JUMP FROM STAIR 0 TO N-1 INSTEAD OF 1 TO N
//recursion : -
//tc : 2^N
//dc :O(N)
int helper(int n, vector<int> &heights)
{
    if (n == 0)
        return 0;
    int left = INT_MAX, right = INT_MAX;
    left = helper(n - 1, heights) + abs(heights[n - 1] - heights[n]);
    if (n > 1)
        right = helper(n - 2, heights) + abs(heights[n - 2] - heights[n]);

    return min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    return helper(n - 1, heights);
}

//Memoization :
//tc: O(n)
//sc : O(N) +O(N)
#include <bits/stdc++.h>
int helper(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
    {
        return dp[n];
    }
    
    int  twoJumps = INT_MAX;
    int oneJumps = helper(n - 1, heights, dp) + abs(heights[n - 1] - heights[n]);
    if (n > 1)
    twoJumps = helper(n - 2, heights, dp) + abs(heights[n - 2] - heights[n]);
    return dp[n] = min(oneJumps, twoJumps);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return helper(n - 1, heights, dp);
}

// tabulation :
// tc: O(N)
// sc : O(N)

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int twoJumps = INT_MAX;
        int oneJumps = dp[i - 1] + abs(heights[i - 1] - heights[i]);
        if (i > 1)
            twoJumps = dp[i - 2] + abs(heights[i - 2] - heights[i]);
        dp[i] = min(oneJumps, twoJumps);
    }
    return dp[n - 1];
}
//space optimisation
//tc:o(n)
//sc:o(1)
int frogJump(int n, vector<int> &heights)
{
    
  int prev1 = 0,prev2=0;
  //prev1 = 0 because to if i am at the 0th stair already then no energy requierd to jump
  //take prev2 any number 0 ,-1 ,-2 beacuse it will not be used in the forst iteration
  //and in the second iteration when i =2 it would be replace by value of prev1

    for (int i = 1; i < n; i++)
    {
        int oneJumps = INT_MAX, twoJumps = INT_MAX;
        oneJumps =prev1 + abs(heights[i - 1] - heights[i]);
        if (i > 1)
            twoJumps = prev2 + abs(heights[i - 2] - heights[i]);
       int curr = min(oneJumps, twoJumps);
       
       prev2 = prev1;
       prev1 = curr;

    }
    return prev1;
}
