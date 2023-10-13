//Idead  : same as book allocation
// bool canPaint(vector<int>&boards ,int n ,int k ,int maximumtimetopaintallboards)
// {
//     int painterscount= 1,timetakentopaintboards= 0;
//     for(int i=0;i<n;i++)
//     {
//         if(timetakentopaintboards + boards[i]<=maximumtimetopaintallboards)
//          timetakentopaintboards+= boards[i];
//         else
//         {
//            painterscount++;
//            if(painterscount > k || boards[i] > maximumtimetopaintallboards)
//               return false;
//            timetakentopaintboards = boards[i];
//         }
//     }
//     return true;
//  }

// int findLargestMinDistance(vector<int> &boards, int k)
// {
//     int n =boards.size();
//     int maxi = INT_MIN,sum=0;
//    for(int i =0;i<n;i++){
//        maxi= max(maxi,boards[i]);
//        sum+=boards[i];
//    }
//     int low = maxi  , high = sum,ans=-1;
//     while(low<=high)
//     {
//         int mid = low + (high - low)/2;
//         if(canPaint(boards,n,k,mid))
//         {
//             ans = mid;
//            high = mid-1;
//         }
//         else
//         {
//            low = mid +1;
//         }
//     }
//     return ans;
// }