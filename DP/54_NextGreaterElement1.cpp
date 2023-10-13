#include<bits/stdc++.h>
using namespace std;

//optimal solution 
//TC : O(N + N)
//Striver video

// Approach 
// 1. we start from last because for last element nge is always -1
// we pop elements from stack till stack st.top() < nums[i] (means until we find a greater element on right)
// if stack becomes empty then it means there are no nge for arr[i] , so nge[i] = -1;
// then we push arr[i] in stack because it can be nge for some other element
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> hash(1e4 + 1, -1);
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        int e = nums2[i];
        while (!st.empty() && st.top() <= e)
            st.pop();
        if (st.size() == 0)
        {
            hash[e] = -1;
        }
        else
        {
            hash[e] = st.top();
        }
        st.push(e);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(hash[nums1[i]]);
    }
    return ans;
}