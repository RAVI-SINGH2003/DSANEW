// In this question we can pick an element once. example arr[0] can be picked only once for a combination.
// There are duplicates also.
// we want to generate all unique combinations such that the elements in the combination sum to target_sum.

// Approach -1 using sets
// TC: O(2^N *klog(k))
//  class Solution
// {
//  public:
//      set<vector<int>> s;
//      void helper(vector<int> &v, vector<int> temp, int target, int sum, int idx)
//      {
//          if (sum == target)
//          {
//              sort(temp.begin(), temp.end());
//              s.insert(temp);
//              return;
//          }
//          if (sum > target || idx >= v.size())
//          {
//              return;
//          }
//          temp.push_back(v[idx]);
//          sum += v[idx];
//          helper(v, temp, target, sum, idx + 1);
//          temp.pop_back();
//          sum -= v[idx];
//          helper(v, temp, target, sum, idx + 1);
//      }
//      vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
//      {
//          helper(candidates, {}, target, 0, 0);
//          vector<vector<int>> ans(s.begin(), s.end());
//          return ans;
//      }
//  };

// Approach -2(optimal)

// TC : O(2^N *K)  //k is the aveage length of combinations  *k for storing temp in ans
// SC: O(k*x) x=no of combinations and k = average length of combinations
//  AS = O(N)

// class Solution
// {
// public:
//     void solve(vector<int> &candidates, int target, vector<int> ds, vector<vector<int>> &ans, int index)
//     {

//         if (target == 0)
//         {
//             ans.push_back(ds);
//             return;
//         }
//         if (index == candidates.size() || target < 0)
//         {
//             return;
//         }
//         for (int j = index; j < candidates.size(); j++)
//         {
//             if (j == index || candidates[j] != candidates[j - 1])
//             {
//                 ds.push_back(candidates[j]);
//                 solve(candidates, target - candidates[j], ds, ans, j + 1);
//                 ds.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
//     {
//         vector<vector<int>> ans;
//         sort(candidates.begin(), candidates.end());
//         vector<int> ds;
//         solve(candidates, target, ds, ans, 0);
//         return ans;
//     }
// };


// #Approach - 3 
//pick element
//if you skip make sure to skip all duplicate occourences.

// class Solution
// {
// public:
//     void solve(vector<int> &candidates, int target, vector<int> ds, vector<vector<int>> &ans, int index)
//     {

//         if (target < 0)
//         {
//             return;
//         }
//         if (index == candidates.size())
//         {
//             if (target == 0)
//                 ans.push_back(ds);
//             return;
//         }
//         // pick
//         ds.push_back(candidates[index]);
//         solve(candidates, target - candidates[index], ds, ans, index + 1);
//         ds.pop_back();

//         // not pick so skip all duplicate occourences of candidates[index];
//         while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1])
//             index++;
//         solve(candidates, target, ds, ans, index + 1);
//     }
//     vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
//     {
//         vector<vector<int>> ans;
//         sort(candidates.begin(), candidates.end());
//         vector<int> ds;
//         solve(candidates, target, ds, ans, 0);
//         return ans;
//     }
// };