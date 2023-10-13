<<<<<<< HEAD
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int m  = matrix.size();
//         int n = matrix[0].size();
//         vector<int> ans;
//         int rs = 0 , re  = m-1 , cs =0 , ce = n-1;
//         while ( rs <= re && cs <= ce){
//             for( int col  = cs ;col <=ce ;col++){
//               ans.push_back(matrix[rs][col]);  
//             }
//             rs++;
//              for( int row  = rs ;row <=re ;row++){
//               ans.push_back(matrix[row][ce]);  
//             }
//             ce--;
//             if(rs>  re || cs> ce)  break;
//             for(int col = ce ; col>=cs ;col--){
//                 ans.push_back(matrix[re][col]);
//             }
//             re--;
//            for( int row  = re ;row>=rs ;row--){
//               ans.push_back(matrix[row][cs]);  
//             }
//             cs++;
//         }
//         return ans;
//     }
=======
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int m  = matrix.size();
//         int n = matrix[0].size();
//         vector<int> ans;
//         int rs = 0 , re  = m-1 , cs =0 , ce = n-1;
//         while ( rs <= re && cs <= ce){
//             for( int col  = cs ;col <=ce ;col++){
//               ans.push_back(matrix[rs][col]);  
//             }
//             rs++;
//              for( int row  = rs ;row <=re ;row++){
//               ans.push_back(matrix[row][ce]);  
//             }
//             ce--;
//             if(rs>  re || cs> ce)  break;
//             for(int col = ce ; col>=cs ;col--){
//                 ans.push_back(matrix[re][col]);
//             }
//             re--;
//            for( int row  = re ;row>=rs ;row--){
//               ans.push_back(matrix[row][cs]);  
//             }
//             cs++;
//         }
//         return ans;
//     }
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
// };