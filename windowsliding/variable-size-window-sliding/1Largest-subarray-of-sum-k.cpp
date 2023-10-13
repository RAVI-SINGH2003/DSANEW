//approach for positive number array only
//  int lenOfLongSubarr(int A[],  int N, int K) 
//     { 
//         int maxi = 0;
//         int i =0 ,j=0;
//         long long sum = 0;
//         while(j<N)
//         {
//             sum+= A[j];
//             if(sum<K) 
//             j++;
//             else if(sum == K ) {
//                 maxi=max(maxi , j-i+1);
//                 j++;
//             }
//             else if(sum > K)
//             {
//                 while(sum > K)
//                 {
//                     sum= sum -A[i];
//                     i++;
//                 }
//                 j++;
//             }
//         }
//        return maxi;
//     } 


//Approach -2 using hash maps for both -ve and +ve number array
/*int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<int,int> mpp;
        int sum=0,ans=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];    //sum
            if(sum==K)    //if this sum is equal to K then at i+1 is obiviosuly longest length subarray with sum k;
            {
               ans=i+1;
            }
            else if(mpp.find(sum-K)!=mpp.end()) //phir check karte hai ki sum-k aya hai kya aaya hai to i-mpp[sum-k] se mill
                                                 //jaega length new sub aray with sum k ka
            {
                
                ans = max(ans ,i- mpp[sum-K]);
            }
            if(mpp.find(sum)==mpp.end())   <--important// phir hum check karenege ki kya ye sum pehle to nahi aaya agar nahi aya to hi dalna  is sum ke liye index
                                            // kyunki pehle hi agar ye sum aya hoga to uski wo kafi pehle hoga pos me . to
            mpp[sum] =i;                    
                                            //  agar nayi index upadate kardenge to bad me mpp[sum-k ] dhundenege aur agr wo mpp[sum] ke barabar hai to hume jo naya leng thmilega sum-mpp[sum-] karne pe chhota length milega
                                             
            
        }
        return ans;
    }
    
    */