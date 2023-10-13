//Approach 1
    // int circularSubarraySum(int arr[], int num){
    //     long maxi = INT_MIN;
    //     for(int i=0;i<num;i++)
    //     { long sum =0;
    //        for(int j=i;j<num+i;j++)
    //        {
    //            sum+=arr[j%num];
    //            

//Approach -2
//  int kadene(int arr[],int n)
//     {
//         int maxi=INT_MIN;
//         int sum=0;
//         for(int i=0;i<n;i++)
//         {
//             sum+=arr[i];
//             maxi=max(maxi,sum);
//             if(sum<0)
//             {
//                 sum= 0;
//             }
//         }
//         return maxi;
//     }
//     int circularSubarraySum(int arr[], int num){
        
//         int max_normal=kadene(arr,num);
//         if(max_normal<0)
//         return max_normal;
//         int totalsum=0;
//         for(int i=0;i<num;i++)
//         {
//             totalsum+=arr[i];
//             arr[i]=-arr[i];   
            
//         }
//       int max_circular= totalsum + kadene(arr,num); //here kadene will give sum of non contriuting elements for max circular subarray sum but sign is reversed
//         return max(max_normal,max_circular);
        
//     }