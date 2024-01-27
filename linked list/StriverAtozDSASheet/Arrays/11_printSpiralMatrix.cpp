#include <bits/stdc++.h>
using namespace std;
// edge case single row and singlw column

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> ans;
    int rs = 0, re = n - 1, cs = 0, ce = m - 1;
    while (rs <= re && cs <= ce)
    {
        // 1st row ;
        for (int c = cs; c <= ce; c++)
        {
            ans.push_back(matrix[rs][c]);
        }
        rs++;
        // last row
        for (int r = rs; r <= re; r++)
        {
            ans.push_back(matrix[r][ce]);
        }
        if (rs > re)
            break;
        ce--;
        // last row
        for (int c = ce; c >= cs; c--)
        {
            ans.push_back(matrix[re][c]);
        }
        if (ce < cs)
            break;
        re--;
        // 1st col
        for (int r = re; r >= rs; r--)
        {
            ans.push_back(matrix[r][cs]);
        }
        cs++;
    }
    return ans;
}