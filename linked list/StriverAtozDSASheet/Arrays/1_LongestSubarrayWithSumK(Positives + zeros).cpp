#include<bits/stdc++.h>
using namespace std;
//Brute force - try all subarrays

//TC : O(nlogn) - with ordered_map
//TC : O(N*N) - with unordered_map
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        // Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Finally, update the map checking the conditions:
        //this is done for zeros in array
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

//optimal - TC : O(2N) as i and j both can move from 0 to n-1

int longestSubarrayWithSumK(vector<int> a, long long k) { 
   int i = 0, j =0;
   int maxLen = 0;
   int n =a.size();
   long long sum = 0;

   while(i<n && j<n){
       sum+=a[j];
       if(sum<k)
       {
           j++;
       }
        else if(sum>k)
        {
           while(i<=j&&sum>k){
               sum-=a[i];
               i++;
           }
           if(sum<k){
               j++;
           }
        } 
        if(sum==k){
           maxLen = max(maxLen,j-i+1);
           j++;
       }
       
   }
   return maxLen;
}