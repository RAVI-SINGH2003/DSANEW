// //phone keypad problem
// class Solution
// {
// public:
//     void helper(int i, string digits, string ds, vector<string> &ans, vector<string> mapping)
//     {
//         if (i == digits.size())
//         {
//             ans.push_back(ds);
//             return;
//         }
//         int number = digits[i] - '0';
//         string value = mapping[number];

//         for (int j = 0; j < value.size(); j++)
//         {
//             ds.push_back(value[j]);
//             helper(i + 1, digits, ds, ans, mapping);
//             ds.pop_back();
//         }
//     }
//     vector<string> letterCombinations(string digits)
//     {
//         vector<string> mapping{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         vector<string> ans;
//         string ds;
//         if (digits.empty())
//             return ans;
//         helper(0, digits, ds, ans, mapping);
//         return ans;
//     }
// };