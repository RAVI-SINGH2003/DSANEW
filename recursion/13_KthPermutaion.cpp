// APPROACH-1
//  TC: O(N!*N)
//  class Solution {
//  public:
//      void helper(string s,int n,int idx,vector<string>&ans)
//      {

//         if(idx==n)
//         {
//             ans.push_back(s);
//             return;
//         }
//         for(int i =idx;i<n;i++)
//         {
//             swap(s[i],s[idx]);
//              helper(s,n,idx+1,ans);

//             swap(s[i],s[idx]);

//         }

//     }
//     string getPermutation(int n, int k) {
//       string s = "";
//       for(int i =1;i<=n;i++)
//       {
//           s+=to_string(i);
//       }

//         vector <string> ans;

//         helper(s,n,0,ans);
//         sort(ans.begin(),ans.end());
//         return ans[k-1];
//     }
// };

// APPROACH-2
//  TC:O(N)
//  void helper(string s, int n, int k, string &ans, vector<int> &factorial)
//  {
//      if (s.size() == 0)
//          return;
//      int idx = k / (factorial[s.size() - 1]);
//      k = k % (factorial[s.size() - 1]);
//      ans += s[idx];
//      s.erase(idx, 1);
//      helper(s, n, k, ans, factorial);
//  }
//  string getPermutation(int n, int k)
//  {

//     string s = "", ans = "";
//     vector<int> factorial(n + 1, 1);
//     int fact = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         s += to_string(i);
//         fact *= i;
//         factorial[i] = fact;
//     }

//     helper(s, n, k - 1, ans, factorial);
//     return ans;
// }

// Approach - 3
//  string getPermutation(int n, int k)
//  {
//      string s = "";
//      for (char ch = '1'; ch <= (char)(n + '0'); ch++)
//          s += ch;
//      string ans = "";
//       k--;
//      while (n > 0)
//      {
//          int val = fact(n - 1);
//          char ch = s[k / val];
//          s.erase(s.find(ch), 1);
//          ans += ch;
//          k %= val;
//          n--;
//      }
//      return ans;
//  }