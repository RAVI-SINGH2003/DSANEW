<<<<<<< HEAD
//Approach-1 TC: O(n*n) SC: 0(n*n) 
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//         vector<vector<int>> tmp = matrix;
//         for(int i =0 ;i<n;i++){
//             for(int j =0 ;j < n;j++)
//             {
//                 tmp[j][n-1-i] = matrix[i][j];
//             }
//         }
//         matrix = tmp;
        
//     }
// };

//Approach -2 : A common method to rotate the image
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
// TC: O(n^2) SC: O(1)
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//         vector<vector<int>> tmp = matrix;
//         for(int i =0 ;i<n;i++){
//             for(int j =0 ;j < n;j++)
//             {
//                 tmp[j][n-1-i] = matrix[i][j];
//             }
//         }
//         matrix = tmp;
        
//     }
=======
//Approach-1 TC: O(n*n) SC: 0(n*n) 
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//         vector<vector<int>> tmp = matrix;
//         for(int i =0 ;i<n;i++){
//             for(int j =0 ;j < n;j++)
//             {
//                 tmp[j][n-1-i] = matrix[i][j];
//             }
//         }
//         matrix = tmp;
        
//     }
// };

//Approach -2 : A common method to rotate the image
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
// TC: O(n^2) SC: O(1)
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//         vector<vector<int>> tmp = matrix;
//         for(int i =0 ;i<n;i++){
//             for(int j =0 ;j < n;j++)
//             {
//                 tmp[j][n-1-i] = matrix[i][j];
//             }
//         }
//         matrix = tmp;
        
//     }
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
// };