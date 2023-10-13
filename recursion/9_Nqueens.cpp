// APPROACH-1
// Time Complexity : O(N!*N), Since we have N choices in the first row, then N-1 choices in the second row and so on so the overall complexity become O(N!)
// Space Complexity: O(N*N), Just the board and recursive stack space o(n)

// bool canPlace(vector<string>&board , int row, int col, int n)
// {
//     //col check
//     for (int r = 0; r < row; r++)
//     {
//         if (board[r][col] == 'Q')
//             return false;
//     }
//     int x = row - 1, y = col - 1;

//     //left upper digaonal check
//     while (x >= 0 && y >= 0)
//     {
//         if (board[x][y] == 'Q')
//             return false;
//         x--;
//         y--;
//     }
//     //right upper diagonal check
//     x = row - 1, y = col + 1;
//     while (x >= 0 && y < n)
//     {
//         if (board[x][y] == 'Q')
//             return false;
//         x--;
//         y++;
//     }
//     return true;
// }
// void helper(vector<string> &board, vector<vector<string>> &ans, int n,int row)
// {
//     if (row == n)
//     {
//         ans.push_back(board);
//         return;
//     }
//     for (int col = 0; col < n; col++)
//     {
//         if (canPlace(board, row, col, n))
//         {
//             board[row][col] = 'Q';
//             helper(board, ans, n,row+1);
//             board[row][col] = '.';
//         }
//     }
// }
// vector<vector<string>> solveNQueens(int n)
// {
//     vector<vector<string>> ans;
//     vector<string> board(n);
//     string s(n, '.');
//     for (int i = 0; i < n; i++)
//     {
//         board[i] = s;
//     }
//     helper(board, ans, n,row);
//     return ans;
// }

// APPROACH-2 :hashing
// optimising canPlace part
//  Time Complexity : O(N!*N), Since we have N choices in the first row, then N-1 choices in the second row and so on so the overall complexity become O(N!)
//  Space Complexity: O(N*N) +O(N) +O(2*N -1) +O(2*N-1), Just the board and leftCheck,upperDiagonal,upperRightDiagonal
//  AS = recursive stack space o(n)

//  void helper(int row, vector<string> &board, vector<int> &colCheck, vector<int> &upperRightDiagonal, vector<int> &upperLeftDiagonal, vector<vector<string>> &ans, int n)
//  {
//      if (row == n)
//      {
//          ans.push_back(board);
//          return;
//      }
//      for (int col = 0; col < n; col++)
//      {
//          if (colCheck[col] == 0 && upperLeftDiagonal[n - 1 + col - row] == 0 && upperRightDiagonal[row + col] == 0)
//          {
//              board[row][col] = 'Q';
//              colCheck[col] = 1;
//              upperLeftDiagonal[n - 1 + col - row] = 1;
//              upperRightDiagonal[row + col] = 1;
//              helper(row + 1, board, rowCheck, upperRightDiagonal, upperLeftDiagonal, ans, n);
//              board[row][col] = '.';
//              rowCheck[col] = 0;
//              upperLeftDiagonal[n - 1 + col - row] = 0;
//              upperRightDiagonal[row + col] = 0;
//          }
//      }
//  }
//  vector<vector<string>> solveNQueens(int n)
//  {
//      vector<vector<string>> ans;
//      vector<string> board(n);
//      string s(n, '.');
//      for (int i = 0; i < n; i++)
//      {
//          board[i] = s;
//      }
//      vector<int> colCheck(n);
//      vector<int> upperLeftDiagonal(2 * n - 1);
//      vector<int> upperRightDiagonal(2 * n - 1);
//      helper(0, board, colCheck, upperRightDiagonal, upperLeftDiagonal, ans, n);
//      return ans;
//  }