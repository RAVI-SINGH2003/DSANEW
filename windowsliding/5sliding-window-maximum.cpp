//https://www.interviewbit.com/problems/sliding-window-maximum/
// #include<list>
// vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
//     vector<int> ans;
    
//     int i=0,j=0;
//      list <int> l;   // largest element list ke front me hoga always 
 
//      l.push_back(A[0]);
    
//     while(j<A.size())
//     {  
        
//        if(j > 0)
//        {   
//         int ele= A[j];                                                   
//            while( !l.empty() && ele >l.back())  //remove all elements from the list which are less than A[j] taki hume descending order me list me elements mil sake 
//            {                                    // like agar 5 3 store the list me aur agar A[j] 4 aagaya to 5 ke bad to 4 aana tha isliye maine 4 se chhote element hataye to 3 hatega
//                l.pop_back();
//            }
//            l.push_back(A[j]);                  // aur phir 4 ko push_back mar
//        }
    
        
        
//         if(j-i+1<B) 
//         j++;
//         else if(j-i+1==B)
//         {
//             ans.push_back(l.front());  // maximum element front pe hai always kynki humne list hi aise maintain ki hai ki elements descending order me store hai
//             if(A[i]==l.front())        // agar jo element hum remove karenge window ko badhate samay wohi maximum element hai to ab list ke front me next max element store ho jana chhaiye tha
//             {                          // iske liye just pop_front mar kyunki next max element to iske bad hi baitha hai kynki list me elements descending order me store hai.
//                 l.pop_front();
//             }
            
//             i++;        //slide window;
//             j++;
//         }
//     }  
//     return ans;
// }