#include<bits/stdc++.h>
using namespace std;
int LongestBitonicSequence(vector<int> nums)
{
    int n = nums.size();
    vector<int> forward(n, 1), backward(n, 1);
    // finding LIS from start
    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i])
            {
                forward[i] = max(forward[i], 1 + forward[prev]);
            }
        }
    }

    // finding LIS from end
    for (int i = n - 2; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (nums[prev] < nums[i])
            {
                backward[i] = max(backward[i], 1 + backward[prev]);
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, forward[i] + backward[i] - 1);
    }
    return maxi;
}