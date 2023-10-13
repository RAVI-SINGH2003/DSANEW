// T.C : O(N * 2 ^ N) A.S : O(N)

// class Solution
// {
// public:
//     bool isPalindrome(string s1)
//     {
//         int i = 0, j = s1.size() - 1;
//         while (i < j)
//         {
//             if (s1[i] != s1[j])
//                 return false;
//             i++;
//             j--;
//         }

//         return true;
//     }
//     void helper(string s, vector<string> temp, vector<vector<string>> &ans, int idx)
//     {

//         if (idx == s.size())
//         {
//             ans.push_back(temp);
//             return;
//         }
//         string s1 = "";
//         for (int i = idx; i < s.size(); i++)
//         {
//             s1 += s[i];
//             if (isPalindrome(s1))
//             {
//                 temp.push_back(s1);
//                 helper(s, temp, ans, i + 1);
//                 temp.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s)
//     {
//         vector<vector<string>> ans;
//         helper(s, {}, ans, 0);
//         return ans;
//     }
// };

