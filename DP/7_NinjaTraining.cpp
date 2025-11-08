#include <bits/stdc++.h>
using namespace std;
//TC :O(2^N)
//SC :O(N)
int maxiMerit_R(int n, vector<vector<int>> &points, int last)
{
    if (n == 0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
            if (i != last)
                maxi = max(maxi, points[0][i]);
        return maxi;
    }
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            maxi = max(maxi, maxiMerit_R(n - 1, points, i) + points[n][i]);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{

    return maxiMerit_R(n - 1, points, 3);
}
// TC :O(N)
// SC :O(N) +O(N)

int maxiMerit_M(int day, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{

    if (day == 0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            maxi = max(maxi, maxiMerit_M(day - 1, points, i, dp) + points[day][i]);
        }
    }

    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return maxiMerit_M(n - 1, points, 3, dp);
}

// TC :O(N*4*3)=)(N)
// SC :O(N) +O(N)
int maxiMerit_T(int day, vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1],points[0][2]));

    for (int dayNo = 1; dayNo < n; dayNo++)
    {
        for (int lastTask = 0; lastTask <4; lastTask++)
        {

            for (int task = 0; task < 3; task++)
            {
                if (task != lastTask)
                {
                    int point = dp[dayNo - 1][task] + points[dayNo][task];
                    dp[dayNo][lastTask] = max(dp[dayNo][lastTask], point);
                }
            }
        }
    }

    return dp[n - 1][3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return maxiMerit_T(n, points);
}
// TC :O(N*4*3)
// SC :O(4)

int maxiMerit_T(int day, vector<vector<int>> &points)
{
    int n = points.size();
    // vector<vector<int>> dp(n, vector<int>(4, -1));
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int dayNo = 1; dayNo < n; dayNo++)
    { 
        vector<int> cur(4,0);
        for (int lastTask = 0; lastTask <4; lastTask++)
        {

            for  (int task = 0; task < 3; task++)
            {
                if (task != lastTask)
                {
                    int point = prev[task] + points[dayNo][task];
                    cur[lastTask] = max(cur[lastTask], point);
                }
            }
            
        }
        prev = cur;
    }

    return prev[3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return maxiMerit_T(n, points);
}