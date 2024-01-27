#include<bits/stdc++.h>
using namespace std;

//when no of + and - are equal
//TC : O(N)
//SC : O(1)

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int posIdx = 0, negIdx = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[posIdx] = nums[i];
            posIdx += 2;
        }
        else
        {
            ans[negIdx] = nums[i];
            negIdx += 2;
        }
    }
    return ans;
}
//when no of pos and neg are not equal
//TC : O(N)
//SC : O(N)

void rearrange(int arr[], int n)
{
    vector<int> neg, pos;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }
    int i = 0, j = 0;
    int ind = 0;
    while (i < pos.size() && j < neg.size())
    {
        arr[ind++] = pos[i++];
        arr[ind++] = neg[j++];
    }
    while (i < pos.size())
    {
        arr[ind++] = pos[i++];
    }
    while (j < neg.size())
    {
        arr[ind++] = neg[j++];
    }
}