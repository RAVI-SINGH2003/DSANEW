#include <bits/stdc++.h>
using namespace std;

// Help - Priyansh aggarwal video - https://www.youtube.com/watch?v=96RG7EBF8LI
// queries[i] = [l,r,val];
vector<int> oneD_array_diff(vector<int> &nums, vector<vector<int>> &queries)
{
    for (auto q : queries)
    {
        int l = q[0], r = q[1], val = q[2];
        nums[l] += val;
        if (r + 1 < nums.size())
            nums[r + 1] -= val;
    }

    // prefix sum or cumulative sum

    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
    }

    return nums;
}

// Help - codestorywithmik  - https://www.youtube.com/watch?v=GluIvp5NaGw&t=756s
//  queries[i] = [r1,c1,r2,c2,val];
// matrix =n*n
vector<vector<int>> twoD_array_diff(vector<vector<int>> &matrix, vector<vector<int>> &queries)
{
    int n = matrix.size();
    for (auto q : queries)
    {
        int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3], val = q[4];

        for (int i = r1; i <= r2; i++)
        {
            matrix[i][c1] += val;
            if (c2 + 1 < n)
                matrix[i][c2 + 1] += val;
        }
    }

    // prefix sum or cumulative sum

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    return matrix;
}