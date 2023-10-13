#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {5, 4, 11, 1, 16, 8};
    int n = nums.size();
    int lis_size = 1;
    int lisEndIndex = 0;
    vector<int> dp(n, 1);
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int prev = i - 1; prev >= 0; prev--)
        {
            if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
            {
                parent[i] = prev;
                dp[i] = 1 + dp[prev];
            }
        }
        if (dp[i] > lis_size)
        {
            lis_size = dp[i];
            lisEndIndex = i;
        }
    }
    cout << "LIS  SIZE is : " << lis_size << endl;
    // finding the lis steps : -
    // 1. finding the index of max element in dp array which is lis length

    // 2.tracing back path by parent array;

    int lastindex = lisEndIndex;
    vector<int> LIS(lis_size);
    int idx = lis_size - 1;
    while (parent[lastindex] != lastindex)
    {
        LIS[idx--] = nums[lastindex];
        lastindex = parent[lastindex];
    }
    LIS[idx] = nums[lastindex];
    for (int e : LIS)
    {
        cout << e << " ";
    }
}