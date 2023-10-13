<<<<<<< HEAD
// Minimum Cost To Make String Valid
// Sample Input 1:
// 2
// {{{}
// {{}{}}
// Sample Output 1:
// 1
// 0

// int findMinimumCost(string str)
// {
//     int n = str.size();
//     if (n & 1)
//         return -1;
//     stack<char> st;
//     for (int i = 0; i < n; i++)
//     {
//         char ch = str[i];

//         if (ch == '{')
//             st.push(ch);
//         else
//         {
//             if (!st.empty() && st.top() == '{')
//                 st.pop();
//             else
//                 st.push(ch);
//         }
//     }
//     int opening = 0, closing = 0;
//     while (!st.empty())
//     {
//         if (st.top() == '{')
//             opening++;
//         else
//             closing++;
//         st.pop();
//     }
//     int ans = (opening + 1) / 2 + (closing + 1) / 2;
//     return ans;
=======
// Minimum Cost To Make String Valid
// Sample Input 1:
// 2
// {{{}
// {{}{}}
// Sample Output 1:
// 1
// 0

// int findMinimumCost(string str)
// {
//     int n = str.size();
//     if (n & 1)
//         return -1;
//     stack<char> st;
//     for (int i = 0; i < n; i++)
//     {
//         char ch = str[i];

//         if (ch == '{')
//             st.push(ch);
//         else
//         {
//             if (!st.empty() && st.top() == '{')
//                 st.pop();
//             else
//                 st.push(ch);
//         }
//     }
//     int opening = 0, closing = 0;
//     while (!st.empty())
//     {
//         if (st.top() == '{')
//             opening++;
//         else
//             closing++;
//         st.pop();
//     }
//     int ans = (opening + 1) / 2 + (closing + 1) / 2;
//     return ans;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
// }