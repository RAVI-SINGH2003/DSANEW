// APPROACH-1
//  TC : O(N!*N) = *n for for loop from 0 to n-1
 //  SC: o(n) + o(n)  recursion + vis
//  AS:O(N)

// class Solution
// {
// public:
//     void solve(auto &ans, auto ds, auto &nums, auto &vis)
//     {
//         if (ds.size() == nums.size())
//         {
//             ans.push_back(ds);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (!vis[i])
//             {
//                 ds.push_back(nums[i]);
//                 vis[i] = 1;
//                 solve(ans, ds, nums, vis);
//                 ds.pop_back();
//                 vis[i] = 0;
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> vis(n, 0);
//         vector<vector<int>> ans;
//         vector<int> ds;
//         solve(ans, ds, nums, vis);
//         return ans;
//     }
// };

//APPROACH-2
//TC : O(N!*N) = *N for storing temp in ans
//SC : O(N!*N) for storing permutaion in array; 
// AS:O(N)

// void helper(vector<int> &nums, vector<vector<int>> &ans, int idx)
// {
//     if (idx == nums.size())
//     {
//         ans.push_back(nums);
//         return;
//     }
//     int n = nums.size();
//     for (int i = idx; i < n; i++)
//     {
//         swap(nums[i], nums[idx]);
//         helper(nums, ans, idx + 1);
//         swap(nums[i], nums[idx]);
//     }
// }
// vector<vector<int>> permute(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     helper(nums, ans, 0);
//     return ans;
// }