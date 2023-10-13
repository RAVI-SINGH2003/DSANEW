//This is a modification of 1_print_subsequences.

// https://leetcode.com/problems/subsets-ii/
//  void helper(vector<int> &nums, vector<int> temp, int idx, vector<vector<int>> &ans)
//  {
//      ans.push_back(temp);
//      if(idx == n) return;
//      for (int i = idx; i < nums.size(); i++)
//      {
//         if (i > idx  && nums[i]== nums[i - 1])
//         {
//            continue;
//         }
//         else{
//             temp.push_back(nums[i]);
//             helper(nums, temp, i + 1, ans);
//             temp.pop_back();
//
//          }
//     }
// }
// vector<vector<int>> subsetsWithDup(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> ans;
//     helper(nums, {}, 0, ans);
//     return ans;
// }
// TC : O(2^N *N)  *N for putting temp in ans here we have assumed the length of each subset is n for simplicity
// SC: O(2^N*K) where K is the average length of subsets
// Auxillary space : O(N) = depth of recursion tree