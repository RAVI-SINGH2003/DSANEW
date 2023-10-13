/* striver explanation
int Search(vector<int> arr, int k) {

int low = 0,high = arr.size()-1;
while(low<=high)
{
    int mid = low + (high-low)/2;
    if(arr[mid]==k)
    return mid ;
    
    else if(arr[low]<=arr[mid])
    {
        //left part(low to mid) is sorted
        
        //figure out if k lies on the left half
        if(arr[low]<=k && k <= arr[mid] )
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    else
    {
         //right part (mid+1 to high) is sorted

         //figure out if k lies on the right half
        if(arr[mid] <= k && k<=arr[high])
        {
            low = mid+1;
        }
        else
        {
            high = mid -1;
        }
    }
    
}
      return -1; 
}
*/