#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int sum = 0, maxi = INT_MIN;
    int left = 0, ansRight = 0, ansLeft = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (maxi < sum)
        {
            maxi = sum;
            ansRight = i;
            ansLeft = left;
        }
        if (sum < 0)
        {
            sum = 0;
            left = i + 1;
        }
    }
    cout << ansLeft << " " << ansRight;
    return maxi;
}
