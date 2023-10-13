/*
    int partition (int arr[], int low, int high)
    {
       //pepcoding partition an array wala video dekh
       //idea 2 pointers i,j
       //from low to j-1 elements <=pivot
       //from j to i-1 elements >pivot
       //from i to high unknown

        int pivot = arr[high];
         int i =0,j=0;
         while(i<high)
         {
             if(arr[i] > pivot)
             i++;
             else
             {
                 swap(arr[i],arr[j]);
                 i++;
                 j++;
             }
         }
         swap(arr[high], arr[j]);
         return j;
    }
 void quickSort(int arr[], int low, int high)
    {
        if(low <high)
       {
           int pivotIndex = partition(arr,low,high);
           quickSort(arr,low,pivotIndex-1);
           quickSort(arr,pivotIndex+1,high);
       }
    }
    */
