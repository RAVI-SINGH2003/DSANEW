<<<<<<< HEAD
//https://leetcode.com/problems/search-a-2d-matrix/

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int  m = matrix.size();
//         int  n = matrix[0].size();
//         int i = 0 ,j = m*n-1;
//         while( i <= j )
//         {
//             int mid = (i+j)>>1;
//             int val =matrix[mid/n][mid%n];
//             if(val==target)
//             {
//                 return true;
//             }
//             else if(val > target)
//             {
//                 j--;
//             }
//             else
//             {
//                 i++;
//             }
//         }
//         return false;
//     }
// };

// Approach -2
//class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//          int  m = matrix.size();
//         int  n = matrix[0].size();
//         int i = 0 ,j = n-1;
//         while( i < m && j>=0 )
//         {
//             if(matrix[i][j]==target)
//             {
//                 return true;
//             }
//             else if(matrix[i][j] > target)
//             {
//                 j--;
//             }
//             else
//             {
//                 i++;
//             }
//         }
//         return false;
//     }
=======
//https://leetcode.com/problems/search-a-2d-matrix/

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int  m = matrix.size();
//         int  n = matrix[0].size();
//         int i = 0 ,j = m*n-1;
//         while( i <= j )
//         {
//             int mid = (i+j)>>1;
//             int val =matrix[mid/n][mid%n];
//             if(val==target)
//             {
//                 return true;
//             }
//             else if(val > target)
//             {
//                 j--;
//             }
//             else
//             {
//                 i++;
//             }
//         }
//         return false;
//     }
// };

// Approach -2
//class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//          int  m = matrix.size();
//         int  n = matrix[0].size();
//         int i = 0 ,j = n-1;
//         while( i < m && j>=0 )
//         {
//             if(matrix[i][j]==target)
//             {
//                 return true;
//             }
//             else if(matrix[i][j] > target)
//             {
//                 j--;
//             }
//             else
//             {
//                 i++;
//             }
//         }
//         return false;
//     }
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
// };