#include <bits/stdc++.h>
using namespace std;
// Help - luv prefix sum video - https://www.youtube.com/watch?v=nZe7P674xZo&t=1222s
//  In prefix sum questions try to use 1 based indexing as l and r are also 1 based many times.
int main()
{
    int q, n;
    cin >> q >> n;
    vector<vector<int>> nums(n + 1, vector<int>(n + 1));
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nums[i][j];
            pref[i][j] = nums[i][j] + pref[i - 1][j] + pref[i][j - 1] -  pref[i - 1][j - 1];
        }
    }

    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1] << endl;
    }
}