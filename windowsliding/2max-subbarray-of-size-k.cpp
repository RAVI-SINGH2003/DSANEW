//  long maximumSumSubarray(int K, vector<int> &Arr , int N){
//         // code here 
//         long sum =0,mx= INT_MIN;
//         int i=0,j=0;
//         while(j<N)
//         {
//             sum+=Arr[j];           // do some calculation  
//             if(j-i+1<K)            //make window of size k
//             {
//                 j++;
//             }
//             else if(j-i+1==K)    // when window of size k acheived
//             {
//                 mx= max(mx,sum); // do some calculation first for answer
//                 sum-=Arr[i];     //before sliding the window udo the calculation on the element A[i] as it has to be removed from window 
//                 i++;            // move window;
//                 j++;
//             }
//         }
//         return mx;
//     }