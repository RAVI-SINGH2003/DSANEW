<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//TC :O(K*N);
//SC :O(N)
int solve_R(int n ,int k,vector<int>&v)
{
     if(n==0)
     return 0;
     int minEnergy = INT_MAX;
     for(int i=1;i<=k;i++)
     {
        if(n>=i)
        {
           minEnergy = min(minEnergy,(solve_R(n-i,k,v)+abs(v[n]-v[n-i])));
        }
        else{
            break;
        }
       
     }
     return minEnergy;
}
// TC :O(N*k);
// SC :O(N) +O(N)
int solve_M(int n ,int k,vector<int>&v,vector<int>&dp)
{
     if(n==0)
     return 0;
     int minEnergy = INT_MAX;
     if(dp[n]!=-1)
     return dp[n];
     for(int i=1;i<=k;i++)
     {
        if(n-i>=0)
        {
           minEnergy = min(minEnergy,(solve_M(n-i,k,v,dp)+abs(v[n]-v[n-i])));
        }
        else{
            break;
        }
       
     }
     return dp[n]=minEnergy;
}
// TC :O(N*k);
// SC :O(N)
int solve_T(int n, int k, vector<int> &v)
{
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;

    for(int j =1;j<n;j++)
    {
       
        for (int i = 1; i <= k; i++)
        {
            if (j-i >= 0)
            {
               dp[j]= min(dp[j], (dp[j - i] + abs(v[j] - v[j - i])));
            }
            else
            {
                break;
            }
        }

    }
  
    return dp[n-1];
}
//no space optimization is possible  
 
int main()
{
    int n ,k;
    cin >>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<solve_R(n-1,k,v)<<endl;
    vector<int> dp(n,-1);
    cout<<solve_M(n-1,k,v,dp)<<endl;
    cout<<solve_T(n,k,v)<<endl;
=======
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//TC :O(K^N);
//SC :O(N)
int solve_R(int n ,int k,vector<int>&v)
{
     if(n==0)
     return 0;
     int minEnergy = INT_MAX;
     for(int i=1;i<=k;i++)
     {
        if(n>=i)
        {
           minEnergy = min(minEnergy,(solve_R(n-i,k,v)+abs(v[n]-v[n-i])));
        }
        else{
            break;
        }
       
     }
     return minEnergy;
}
// TC :O(N);
// SC :O(N) +O(N)
int solve_M(int n ,int k,vector<int>&v,vector<int>&dp)
{
     if(n==0)
     return 0;
     int minEnergy = INT_MAX;
     if(dp[n]!=-1)
     return dp[n];
     for(int i=1;i<=k;i++)
     {
        if(n>=i)
        {
           minEnergy = min(minEnergy,(solve_M(n-i,k,v,dp)+abs(v[n]-v[n-i])));
        }
        else{
            break;
        }
       
     }
     return dp[n]=minEnergy;
}
// TC :O(N);
// SC :O(N)
int solve_T(int n, int k, vector<int> &v)
{
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;

    for(int j =1;j<n;j++)
    {
       
        for (int i = 1; i <= k; i++)
        {
            if (j >= i)
            {
               dp[j]= min(dp[j], (dp[j - i] + abs(v[j] - v[j - i])));
            }
            else
            {
                break;
            }
        }

    }
  
    return dp[n-1];
}
//no space optimization is possible  
 
int main()
{
    int n ,k;
    cin >>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<solve_R(n-1,k,v)<<endl;
    vector<int> dp(n,-1);
    cout<<solve_M(n-1,k,v,dp)<<endl;
    cout<<solve_T(n,k,v)<<endl;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}