#include <bits/stdc++.h>
using namespace std;

// TC : O(n*m)
// SC : O(m+n)
void setZeroes(vector<vector<int>> &matrix)
{
    vector<int> row(matrix.size());
    vector<int> col(matrix[0].size());
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// TC : O(n*m)
// SC : O(1)
// approach - we are using the first cell of each row and col to check if that row or col has to made zero

void setZeroes(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();
    bool isZeroInFirstRow = false, isZeroInFirstCol = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
                if (i == 0)
                {
                    isZeroInFirstRow = true;
                }
                if (j == 0)
                {
                    isZeroInFirstCol = true;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0 && (matrix[i][0] == 0 || matrix[0][j] == 0))
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (isZeroInFirstCol)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
    if (isZeroInFirstRow)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
}