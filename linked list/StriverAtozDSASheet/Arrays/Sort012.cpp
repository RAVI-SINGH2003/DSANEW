#include <bits/stdc++.h>
using namespace std;
// 4 areas
// 1. 0 to low - 1 = > area of 0's
// 2. low to mid - 1 = > area of 1's
// 3. mid to high = unknown unsorted area containing random 0 1 2
// 4. high to n - 1 = area of 2's
// start with low = mid = 0, high = n - 1;
void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}