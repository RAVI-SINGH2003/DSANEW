// ye problem na quicksort ke partotion function ka hi modification hai
//    void sortColors(vector<int>& nums) {
//         //0 to low - 1 => 0's
//         //low to mid -1 => 1's
//         //mid to high = unsorted
//         //high + 1 to n-1 = 2's
//         int n = nums.size(); 
//         int low = 0,high = n-1 , mid = low;
//         while(mid<=high)
//         {
//             switch(nums[mid])
//             {
//                 case 0 : swap(nums[mid++] , break;
//                 case 1 : mid++; break;
//                 case 2 : swap(nums[mid] ,nums[high--]); break;
//             }
//         }
//     }