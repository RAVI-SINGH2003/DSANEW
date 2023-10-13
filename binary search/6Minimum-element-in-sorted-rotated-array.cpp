//THIS QUESTION CAN ALSO BE ASKED IN THE WAYS 
//TELL THE NO OF ROTATIONS TO PRODUCE GIVEN SORTED ROTAED ARRAY
//SO INDEX OF MIN ELEMENT IN THE ARRAY - 0 WILL FIVE THE NO OF ROTATIONS WHICH PRODUCED THE GIVEN ARRAY

//  int findMin(int arr[], int n){
//         int low =0,high= n-1,ans;
//         while(low<=high){
            
//            int mid=low+(high-low)/2;
//            if(arr[low] < arr[high])
//            {
//                return arr[low];
//            }
//            else  if(mid==0 || arr[mid] < arr[mid-1])
           
//            return arr[mid];
           
//            else if(arr[low] <=arr[mid])
//            {
//                //left part(from low to mid) is sorted answer lie on right side(unsorted part)
               
//                low = mid +1;
//            }
//            else
//            {  
//                //right part ( from mid+1 to high) is sorted answer lie on left side (unsorted side)
               
//                high = mid - 1;
//            }
//         }
        
//     }