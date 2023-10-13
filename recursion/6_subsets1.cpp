// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
//  class Solution
//  {
//  public:
//      void helper(vector<int> &arr, int sum, vector<int> &ans, int idx)
//      {
//         if (idx == arr.size())
//         {
//             ans.push_back(sum);
//             return;
//         }
//         sum += arr[idx];
//         helper(arr, sum, ans, idx + 1);
//         sum -= arr[idx];
//         helper(arr, sum, ans, idx + 1);
//     }
//     vector<int> subsetSums(vector<int> arr, int N)
//     {
//         vector<int> ans;
//         int sum = 0;
//         helper(arr, sum, ans, 0);
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };
// TC : O(2^N)
// SC: O(2^N)

