#include<bits/stdc++.h>
using namespace std;

//TC : O(N*N)
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxi = -1e9;
    for (int i = 0; i < n; i++)
    {
        int height = heights[i];
        int leftDist = 0, rightDist = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (heights[j] >= height)
            {
                leftDist++;
            }
            else
            {
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (heights[j] >= height)
            {
                rightDist++;
            }
            else
            {
                break;
            }
        }
        int width = leftDist + rightDist + 1;
        int area = width * height;
        maxi = max(maxi, area);
    }
    return maxi;
}

//optimal solution 
//Approach - using NextSmallerElement and Previous Smaller Element
//TC : O(N)
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxi = -1e9;

    vector<int> NextSmallerElementIndex(n, -1), PrevSmallerElementIndex(n, -1);
    stack<int> st;
    // calculating Next Smaller Element Indexes

    //O(N + N)
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            NextSmallerElementIndex[i] = -1;
        }
        else
        {
            NextSmallerElementIndex[i] = st.top();
        }
        st.push(i);
    }
    // emptying stack for next task
    while (!st.empty())
        st.pop();

    // calculating Prev Smaller Element Indexes

    // O(N + N)
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            PrevSmallerElementIndex[i] = -1;
        }
        else
        {
            PrevSmallerElementIndex[i] = st.top();
        }
        st.push(i);
    }

    // O(N)
    for (int i = 0; i < n; i++)
    {
        int height = heights[i];

        int rightWidth = (NextSmallerElementIndex[i] == -1) ? n - 1 - i : (NextSmallerElementIndex[i] - i - 1);
        int leftWidth = (PrevSmallerElementIndex[i] == -1) ? i : (i - PrevSmallerElementIndex[i] - 1);

        int width = leftWidth + 1 + rightWidth;
        int area = width * height;
        maxi = max(maxi, area);
    }
    return maxi;
}





