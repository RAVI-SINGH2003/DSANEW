// WINDOW SLIDING TECHNIQUE

// 1.Identification
// -> Array / String 
// -> subbarray / substring 
// -> max /min / largest /smallest
// // -> window size = k


// 2.Types of window sliding
// -> fixed size window
//    -> window size is given always
//    eg find max subarray sum of size k

// -> variable size window 
//   -> window size or subarray or substring size has to be  found
//   ->largest/smallest subarray of sum k
//   -->may be listor map is used.

//general format of fixed size sliding window problem discissed in https://www.youtube.com/watch?v=LV-BgyeH8yo&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=9
// while(j< size)
// {
//     calculations

//     if(winsize < k)
//     j++;
//     else if(winsize == k)
//     {
//         ans <- calculations
//         calculation for removing a[i]; i.e undo the changes on a[i]
//       i++;
//       j++;
    
//     }
// }

