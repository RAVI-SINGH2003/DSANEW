#include<bits/stdc++.h>
using namespace std;

//brute force solution
// TC :  O(N*N) for worst case like [5,4,3,2,1]
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n);
    for (int i = 0; i < n; i++)
    {
        bool isFound = false;
        int currNge = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                currNge = nums[j];
                isFound = true;
                break;
            }
        }
        if (!isFound)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > nums[i])
                {
                    currNge = nums[j];
                    break;
                }
            }
        }
        nge[i] = currNge;
    }
    return nge;
}

//optimal solution is to use approach of NGE1 
//1.copy the given array
// like arr = [2,1,5,1,3]
//now for arr[0] i.e. 2 we need to arr[1]....arr[4] i.e 1 5 1 3
//now for arr[1] i.e. 1 we need to arr[2]....arr[4], arr[0] i.e  5 1 3,2
//now for arr[2] i.e. 5 we need to arr[3]....arr[4],arr[0], arr[1] i.e 1 3,2,1
//now for arr[3] i.e. 1 we need to arr[4]....arr[4],arr[0], arr[1],arr[2] i.e  3,2,1,5
//now for arr[4] i.e. 3 we need to arr[5]....arr[4],arr[0], arr[1],arr[2], arr[3] i.e  2,1,5,1

// so it creates array double => 2 1 5 1 3  | 2 1 5 1 
//we just add last element to second array as it will make the arrays same
   // 0 1  2 3 4   5 6  7 8  9
// so 2 1  5 1 3 | 2 1  5 1  3
//nge 5 5 -1 3 5   5 5 -1 3 -1

// these are 2n-1 elements we will apply stack opeartion from end
// like NGE1 and i will get my answer
// for index 9 i should access index 4 and that is 9%n = 9%5 = 4
// for index 8 i should access index 3 and that is 8%n = 9%5 = 3
// for index 7 i should access index 2 and that is 7%n = 9%5 = 2
// for index 6 i should access index 1 and that is 6%n = 9%5 = 1
// for index 5 i should access index 0 and that is 5%n = 9%5 = 0

// for index 4 i should access index 4 and that is 9%n = 9%4 = 4
// for index 8 i should access index 3 and that is 8%n = 9%3 = 3
// for index 7 i should access index 2 and that is 7%n = 9%2 = 2
// for index 6 i should access index 1 and that is 6%n = 9%1 = 1
// for index 5 i should access index 0 and that is 5%n = 9%0 = 0


//so it means doing stack opertion twice on the array you will see that 
///nge is calculated to each index.

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> nge(n, -1);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int idx = i % n;
        while (!st.empty() && st.top() <= nums[idx])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            nge[idx] = -1;
        }
        else
        {
            nge[idx] = st.top();
        }
        st.push(nums[idx]);
    }
    return nge;
}