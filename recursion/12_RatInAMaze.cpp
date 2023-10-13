// TC : -O(3^N*N) 
// there are only 3 choices. The place from where the mouse has came, it can not go back at that same place back. This eliminates 1 choice and leaves us with only 3 choices.


// void helper(vector<vector<int>> &m, int n, vector<string> &ans, int i, int j, string s)
// {
//     if (i == n - 1 && j == n - 1)
//     {
//         ans.push_back(s);
//         return;
//     }

//     if (i + 1 < n && m[i + 1][j] != 0)
//     {
//         m[i][j] = 0;
//         helper(m, n, ans, i + 1, j, s + 'D');
//         m[i][j] = 1;
//     }
//     if (i - 1 >= 0 && m[i - 1][j] != 0)
//     {
//         m[i][j] = 0;
//         helper(m, n, ans, i - 1, j, s + 'U');
//         m[i][j] = 1;
//     }
//     if (j + 1 < n && m[i][j + 1] != 0)
//     {

//         m[i][j] = 0;
//         helper(m, n, ans, i, j + 1, s + 'R');
//         m[i][j] = 1;
//     }
//     if (j - 1 >= 0 && m[i][j - 1] != 0)
//     {

//         m[i][j] = 0;
//         helper(m, n, ans, i, j - 1, s + 'L');
//         m[i][j] = 1;
//     }
// }
// vector<string> findPath(vector<vector<int>> &m, int n)
// {
//     if (m[0][0] == 0)
//         return {};
//     vector<string> ans;
//     helper(m, n, ans, 0, 0, "");
//     return ans;
// }