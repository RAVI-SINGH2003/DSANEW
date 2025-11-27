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
// Idea - either at each index start the new sum or take the previous sum + currelement
// reference - codestorywitjmik
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxSum = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};