// Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
// Note: If the array is increasing then just print then last element will be the maximum value.
    //THIS QUSESTION IS COMPLETELY SIMILAR TO PEAK ELEMNT QUESTION EXCEPT THE FACT THAT WE HAVE TO RETIRN THE ELEMENT INSTEAD OF INDEX
    // int findMaximum(int arr[], int n) {
	//      int low = 0,high = n-1,mid;
    //    while(low<=high){     
    //         mid = low + (high-low)/2;
    //        if((mid==0 || arr[mid]>=arr[mid-1] )&& (mid==n-1 || arr[mid] >=arr[mid+1])){
    //            return arr[mid];
    //        }
    //        else if(mid+1<n && arr[mid+1]>arr[mid]){
    //            low = mid+1;
    //        }
    //        else if(mid-1>=0 &&arr[mid-1]>arr[mid]){
    //            high = mid-1;
    //        }
    //    }
    //    return arr[mid];
	// }