#include<bits/stdc++.h>
using namespace std;

// majority elemet - present >N/2 times in an array
// Moore's voting algorithm
// striver video

int majorityElement(int arr[], int n)
{
    int curMaj = arr[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == curMaj)
            count++;
        else
        {
            count--;
            if (count == 0)
            {
                curMaj = arr[i];
                count = 1;
            }
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == curMaj)
            c++;
    }
    return c > n / 2 ? curMaj : -1;
}
// approach 2 nlogn
// int majorityElement(int a[], int size)
// {
//       map<int,int> m;
//       for(int i=0;i<size;i++)
//       {
//           m[a[i]]++;
//           if(m[a[i]]>size/2)
//           return a[i];
//       }
//       return -1;
// }
// approach 3 o(n^2) solution

// ============================================
// element which appears more than n/k times , will be k - 1
// like n/2 -> 1 element
// n/3 -> 2 elements
// codestorywithmik

vector<int> majorityElement(vector<int> &nums)
{
    int c1 = 0, c2 = 0, m1 = -1e8, m2 = -1e8, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == m1)
            c1++;
        else if (nums[i] == m2)
            c2++;
        else if (c1 == 0)
        {
            m1 = nums[i];
            c1++;
        }
        else if (c2 == 0)
        {
            m2 = nums[i];
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    int f1 = 0, f2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (m1 == nums[i])
            f1++;
        if (m2 == nums[i])
            f2++;
    }

    vector<int> ans;

    if (f1 > n / 3)
        ans.push_back(m1);
    if (f2 > n / 3)
        ans.push_back(m2);

    return ans;
}