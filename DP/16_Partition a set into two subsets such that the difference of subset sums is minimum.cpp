#include<bits/stdc++.h>
using namespace std;
//recursion : 
//TC:O(2^N)
//SC:O(N)
int helper(vector<int>&arr,int idx,int sum,int total)
{
    if(idx==0)
    {
        if(sum+arr[0]==total)
           return INT_MAX;
        else
        {
            int value1 =sum+arr[0];
            int value2 = total -value1;
            int diff = abs(value1 - value2);
            return diff;
        }
    }
    int take = helper(arr,idx-1,sum+arr[idx],total);
    int notTake = helper(arr,idx-1,sum,total);
    return min(take,notTake);
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    if(n==1)
        return arr[0];
    int total = 0;
    for(int i =0;i<n;i++)
        total+=arr[i];
    if(total==0)
        return 0;
    return helper(arr,n-1,0,total);
}

// memoization :
// TC:O(N*K)
// SC:O(N)
int helper(vector<int>&arr,int idx,int sum,int total,vector<vector<int>>&dp)
{
    if(idx==0)
    {
        if(sum+arr[0]==total)
           return INT_MAX;
        else
        {
            int value1 =sum+arr[0];
            int value2 = total -value1;
            int diff = abs(value1 - value2);
            return diff;
        }
    }
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    int take = helper(arr,idx-1,sum+arr[idx],total,dp);
    int notTake = helper(arr,idx-1,sum,total,dp);
    return dp[idx][sum]=min(take,notTake);
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    if(n==1)
        return arr[0];
    int total = 0;
    for(int i =0;i<n;i++)
        total+=arr[i];
    if(total==0)
        return 0;
    vector<vector<int>> dp(n,vector<int>(total+1,-1));
    return helper(arr,n-1,0,total,dp);
}
//----------------------------------------------------------------------------------------
// note : here we used the code of dp-14
// in tabulation method we created a matrix dp[0-----n-1][0------k]
// the last row of matrix gives if if have array from 0 to n-1 index
// can target of 0 ,1 ,2,3,4,5,6,7,...........k is possible or not
//if its posssible the we take that sum = this sum we call sum1 the sum of 
// 1 subset
//So total - sum1  = sum2  = the sum of remaining subset
//now we do abs difference of sum1-sum2 and for each sum1 which is possible we do the same process of finding 
//sum2 and take the abs difference and take the min of that of all differences.

//Tabulation : 
//TC : O(N*totalsum)+ O(totalsum)
//SC : O(N*totalsum)
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    int k = total;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool take = false;
            if (target >= arr[idx])
                take = dp[idx - 1][target - arr[idx]];
            bool notTake = dp[idx - 1][target];
            dp[idx][target] = take || notTake;
        }
    }
    //     dp[n-1][0.....k]
    int mini = 1e9;

    //here s1 = 0-k/2 because if
    // suppose in i have array = {0,3,1}
    // k=totalsum = 4
    //   k                               = 0    1     2    3      4  
    //possible(from last row of table)   = yes  yes   no   yes   yes  
    //sum1                               =  0    1     -     3     4
    //sum2  = totalsum-sum1              =  4    3     -     1     0 
    //abs(sum1-sum2)                      =  4   2     -    2       4  
    //so carefully observe that values o f sum1 and sum2 gets flip after half iteration
    //and we do not need to go till last as the values of abs(sum1-sum2) will
    //get repeated as you can see after half of the iteration.
 
     for (int s1 = 0; s1 <= k / 2; s1++)
    {
        if (dp[n - 1][s1])
        {
            int sum1 = s1;
            int sum2 = total - s1;
            mini = min(mini, abs(sum1 - sum2));
        }
    }
    return mini;
}
// space optimised:
// tc : O(n*totalsum)+ O(totalsum)
// sc : O(TotalSum)
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    for (int num : arr)
        total += num;
    int k = total;
    vector<bool> prev(k + 1, false);
    vector<bool> cur(k + 1, false);

    prev[0] = cur[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;
    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool take = false;
            if (target >= arr[idx])
                take = prev[target - arr[idx]];
            bool notTake = prev[target];
            cur[target] = take || notTake;
        }
        prev = cur;
    }

    //     dp[n-1][0.....k]
    int mini = 1e9;
    for (int s1 = 0; s1 <= k / 2; s1++)
    {
        if (prev[s1])
        {
            int sum1 = s1;
            int sum2 = total - s1;
            mini = min(mini, abs(sum1 - sum2));
        }
    }
    return mini;
}
