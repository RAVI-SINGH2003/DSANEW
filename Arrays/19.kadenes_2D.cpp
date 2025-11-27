#include <bits/stdc++.h>
using namespace std;

int maxRectSumBrute(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();

    int maxi = INT_MIN;
    for (int r1 = 0; r1 < n; r1++)
    {
        for (int c1 = 0; c1 < m; c1++)
        {
            for (int r2 = r1; r2 < n; r2++)
            {
                for (int c2 = c1; c2 < m; c2++)
                {
                    int sum = 0;
                    for (int i = r1; i <= r2; i++)
                    {
                        for (int j = c1; j <= c2; j++)
                        {
                            sum += mat[i][j];
                        }
                    }
                    maxi = max(maxi, sum);
                }
            }
        }
    }
    return maxi;
}

int kadenes(vector<int> &arr)
{
    int maxi = arr[0];
    int sum = 0;
    for (int e : arr)
    {
        sum += e;
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int maxRectSumKadenes(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();

    int maxi = INT_MIN;
    for (int cs = 0; cs < m; cs++)
    {
        vector<int> nums(n);
        for (int ce = cs; ce < m; ce++)
        {
            for (int r = 0; r < n; r++)
            {
                nums[r] += mat[r][ce];
            }
            maxi = max(maxi, kadenes(nums));
        }
    }
    return maxi;
}
