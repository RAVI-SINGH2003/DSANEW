#include<bits/stdc++.h>
using namespace std;

int largestArea(vector<int> &heights)
{
    int n = heights.size();
    int maxi = -1e9;

    vector<int> NextSmallerElementIndex(n, -1), PrevSmallerElementIndex(n, -1);
    stack<int> st;
    // calculating Next Smaller Element Indexes

    // O(N + N)
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

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> mat(n, vector<int>(m));

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            mat[r][c] = matrix[r][c] - '0';
        }
    }
    for (int r = 1; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (mat[r][c] == 1)
            {
                mat[r][c] = 1 + mat[r - 1][c];
            }
        }
    }
    int maxi = -1e9;
    vector<int> currLevel(m);
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            currLevel[c] = mat[r][c];
        }
        int currentLevelMaxArea = largestArea(currLevel);
        maxi = max(maxi, currentLevelMaxArea);
    }
    return maxi;
}