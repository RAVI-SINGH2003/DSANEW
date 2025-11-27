#include <bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int> &nums)
{

    int maxi = INT_MIN;
    int n = nums.size();
    int sum = 0;
    int finalStart = 0, finalEnd = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum > maxi)
        {
            maxi = sum;
            finalStart = start;
            finalEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
            start = i + 1;
        }
    }

    for (int i = finalStart; i <= finalEnd; i++)
    {
        cout << nums[i] << " ";
    }

    cout <<endl<< maxi;
}

int main()
{
    vector<int> nums = {100, 3, -1000, 1,5};
    maxSubArray(nums);
}


// 2nd way to implement

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long sum = LLONG_MIN;
        int n = nums.size();

        vector<long long> pref(n);
        pref[0] = nums[0];

        for(int i = 1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }


        for(int i = 0; i<n; i++){
            for(int j = i+k-1; j<n; j+=k){
                long long s = pref[j] - (i>0 ? pref[i-1] : 0);
                if(s>sum){
                    sum = s;
                }
            }
        }
        return sum;
    }
};