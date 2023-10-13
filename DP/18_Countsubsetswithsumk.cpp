<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
// Recursion :
 int helper(vector<int> &num,int tar,int idx)
 {
     if(idx==0)
     {
        if(tar==0 && num[0]==0)
            return 2;
         if(tar==0 || tar==num[0]) return 1;
         return 0;
     }
      int take =0 ;
      if(tar-num[idx]>=0)
       take= helper(num,tar-num[idx],idx-1);
     int notTake =helper(num ,tar,idx-1);
     return take+notTake;
 }
 int findWays(vector<int> &num, int tar)
 {
     return helper(num,tar,num.size()-1);
 }
// Memoization :

int helper(vector<int> &num,int tar,int idx , vector<vector<int>>&dp)
{

    if(idx==0)
    {
       if(tar==0 && num[0]==0)
           return 2;
        if(tar==0 || tar==num[0]) return 1;
        return 0;
    }
    if(dp[idx][tar]!=-1)
        return dp[idx][tar];
     int take =0 ;
     if(tar-num[idx]>=0)
      take= helper(num,tar-num[idx],idx-1,dp);
    int notTake =helper(num ,tar,idx-1,dp);
    return dp[idx][tar] = take+notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return helper(num,tar,n-1,dp);
}

// tabulation  :
 int findWays(vector<int> &num, int tar)
 {
     int n = num.size();
     vector<vector<int>> dp(n,vector<int>(tar+1,0));
     for(int i =0;i<n;i++)
     {
         dp[i][0]=1;
     }
     if(num[0]<=tar)
         dp[0][num[0]] = 1;
     for(int idx=1;idx<n;idx++)
     {
         for(int target = 0;target<=tar;target++)
         {
               int take =0 ;
              if(target>=num[idx])
               take= dp[idx-1][target-num[idx]];
              int notTake =dp[idx-1][target];
              dp[idx][target] = take+notTake;
         }
     }
    return dp[n-1][tar];
 }

// Space optimisation :
 int findWays(vector<int> &num, int tar)
 {
     int n = num.size();
      vector<int>prev(tar+1,0),cur(tar+1,0);
         prev[0] = cur[0]=1;
     if(num[0]<=tar)
         prev[num[0]] = 1;
     for(int idx=1;idx<n;idx++)
     {
         for(int target = 0;target<=tar;target++)
         {
               int take =0 ;
              if(target>=num[idx])
               take= prev[target-num[idx]];
              int notTake = prev[target];
              cur[target] = take+notTake;
         }
         prev=cur;
     }
    return prev[tar];
 }
=======
#include <bits/stdc++.h>
using namespace std;
// Recursion :
 int helper(vector<int> &num,int tar,int idx)
 {
     if(idx==0)
     {
        if(tar==0 && num[0]==0)
            return 2;
         if(tar==0 || tar==num[0]) return 1;
         return 0;
     }
      int take =0 ;
      if(tar-num[idx]>=0)
       take= helper(num,tar-num[idx],idx-1);
     int notTake =helper(num ,tar,idx-1);
     return take+notTake;
 }
 int findWays(vector<int> &num, int tar)
 {
     return helper(num,tar,num.size()-1);
 }
// Memoization :

int helper(vector<int> &num,int tar,int idx , vector<vector<int>>&dp)
{

    if(idx==0)
    {
       if(tar==0 && num[0]==0)
           return 2;
        if(tar==0 || tar==num[0]) return 1;
        return 0;
    }
    if(dp[idx][tar]!=-1)
        return dp[idx][tar];
     int take =0 ;
     if(tar-num[idx]>=0)
      take= helper(num,tar-num[idx],idx-1,dp);
    int notTake =helper(num ,tar,idx-1,dp);
    return dp[idx][tar] = take+notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return helper(num,tar,n-1,dp);
}

// tabulation  :
 int findWays(vector<int> &num, int tar)
 {
     int n = num.size();
     vector<vector<int>> dp(n,vector<int>(tar+1,0));
     for(int i =0;i<n;i++)
     {
         dp[i][0]=1;
     }
     if(num[0]<=tar)
         dp[0][num[0]] = 1;
     for(int idx=1;idx<n;idx++)
     {
         for(int target = 0;target<=tar;target++)
         {
               int take =0 ;
              if(target>=num[idx])
               take= dp[idx-1][target-num[idx]];
              int notTake =dp[idx-1][target];
              dp[idx][target] = take+notTake;
         }
     }
    return dp[n-1][tar];
 }

// Space optimisation :
 int findWays(vector<int> &num, int tar)
 {
     int n = num.size();
      vector<int>prev(tar+1,0),cur(tar+1,0);
         prev[0] = cur[0]=1;
     if(num[0]<=tar)
         prev[num[0]] = 1;
     for(int idx=1;idx<n;idx++)
     {
         for(int target = 0;target<=tar;target++)
         {
               int take =0 ;
              if(target>=num[idx])
               take= prev[target-num[idx]];
              int notTake = prev[target];
              cur[target] = take+notTake;
         }
         prev=cur;
     }
    return prev[tar];
 }
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
