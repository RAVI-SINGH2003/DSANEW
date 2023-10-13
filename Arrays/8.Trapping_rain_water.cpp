// //Approach 1

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int trap=0;
//         int n=height.size();
//         for(int i=0;i<n;i++)
//         {  int lmax=height[i];
//             for(int j=i-1;j>=0;j--)
//             {
//                 lmax=max(lmax,height[j]) ;
//             }
//          int rmax=height[i];
//           for(int j=i+1;j<n;j++)
//             {
//                 rmax=max(rmax,height[j]);
//             }
         
//            trap +=min(lmax -height[i],rmax-height[i]);
//         }
//         return trap;
//     }
// };
// //Approach 2
// class Solution {
// public:
//      int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<int> left (n);
    //     vector<int> right (n);
    //     left[0]= height[0];
    //     right[n-1] = height[n-1];
        
    //     for(int i = 1;i<=n-1;i++)
    //     {
    //         left[i] = max (left[i-1] , height[i-1]);
    //     }
        
    //      for(int i = n-2;i>=0;i--)
    //     {
    //         right[i] = max (right[i+1] , height[i+1]);
    //     }

    //     int ans=0;
    //     for(int i =1;i<=n-2;i++)
    //     {
    //         int temp = min(left[i],right[i]) - height[i]; 
    //         if(temp< 0)
    //             temp =0;
    //          ans+=temp;
            
    //     }
    //     return ans;
        
    // }