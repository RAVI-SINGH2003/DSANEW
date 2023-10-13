// vector<long long> printFirstNegativeInteger(long long int A[],
//                                             long long int N, long long int K)
// {
//     int i = 0, j = 0;
//     list<int> l;
//     vector<long long> ans;
//     while (j < N)
//     {
//         if (A[j] < 0)                        // maintaining a list of all negative no in window of size k
//             l.push_back(A[j]);
//         if (j - i + 1 < K)                   //make window
//         {
//             j++;
//         }
//         else if (j - i + 1 == K)             // window of size k 
//         {
                // do some calc for answer first -ve number in list will be stored 
//             if (l.size() == 0)          //list -empty means no negative number in window  then store 0
//             {
//                 ans.push_back(0);
//             }
//             else if (l.size() != 0)   
//             {
//                 ans.push_back(l.front());
//             }

//             if (l.size() != 0 && A[i] == l.front())   // before moving window if the first negative number in list is the number which we wil lose after we move the window then remove it from list also
//                 l.pop_front();
//             i++;
//             j++;
//         }
//     }
//     return ans;
// }