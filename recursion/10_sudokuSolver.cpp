// TC : O(9^N*N)
// SC : O(1)

// class Solution
// {
// public:
//     bool canPlace(vector<vector<char>> &board, int row, int col, char number)
//     {
//         for (int i = 0; i < 9; i++)
//         {
//             if (board[row][i] == number)
//                 return false;
//             if (board[i][col] == number)
//                 return false;
//             if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == number)
//                 return false;
//         }
//         return true;
//     }
//     bool helper(vector<vector<char>> &board)
//     {
//         for (int i = 0; i < board.size(); i++)
//         {
//             for (int j = 0; j < board[0].size(); j++)
//             {
//                 if (board[i][j] == '.')
//                 {
//                     for (char ch = '1'; ch <= '9'; ch++)
//                     {
//                         if (canPlace(board, i, j, ch))
//                         {
//                             board[i][j] = ch;
//                             if (helper(board))
//                                 return true;
//                             else
//                             {
//                                 board[i][j] = '.';
//                             }
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     void solveSudoku(vector<vector<char>> &board)
//     {
//         helper(board);
//     }
// };