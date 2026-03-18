// #include<stack>
// bool findRedundantBrackets(string &s)
// {
//   stack<char> st;
//     int n=s.size();
//     for(int i=0;i<n;i++)
//     {
//          char ch=s[i];
//         if(ch=='('|| ch=='+'||ch=='-'||ch=='*'||ch=='/')
//          st.push(ch);
//         else if(ch==')')
//         {
//              bool isredundant=true;
//             while(st.top()!='(')
//             {
//               isredundant=false;
//               st.pop();
              
//             }
//             if(isredundant==true)
//                 return true;
//             st.pop();
            
//         }
//     }
//    return false;
// }
