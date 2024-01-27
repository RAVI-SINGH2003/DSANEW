#include<bits/stdc++.h>
using namespace std;

// approach 
// 1. take transpose
//  2.reverse rows
void rotate(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        int s = 0, e = matrix.size() - 1;
        while (s < e)
        {
            swap(matrix[i][s++], matrix[i][e--]);
        }
    }
}