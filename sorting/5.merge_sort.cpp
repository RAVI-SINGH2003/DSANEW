/*void merge(int arr[], int l, int m, int r) // this is the alogorithm of merging two sorted arrays isme extra space use hua hai merge karne ke liye 
    {
      int length1= m -l +1,length2= r-m;
      int *arr1= new int[length1];
      int *arr2= new int[length2];
      int k=l;
      for(int i=0;i<length1;i++)
      {
          arr1[i] = arr[k++];
      }
      k = m+1;
      for(int i=0;i<length2;i++)
      {
          arr2[i] = arr[k++];
      }
      int i = 0, j= 0;
      k =l;
      while(i<length1 && j < length2)
      {
          if(arr1[i] <arr2[j])
          {
              arr[k++] = arr1[i++];
          }
          else
          {
              arr[k++] = arr2[j++];
          }
      }
      while(i<length1)
      {
          arr[k++] = arr1[i++];
      }
       while(j<length2)
      {
          arr[k++] = arr2[j++];
      }
      delete []arr1;
      delete []arr2;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
      if(l<r)
      {
      int mid =l +(r-l)/2;
       mergeSort(arr,l,mid);
       mergeSort(arr,mid+1,r);
       merge(arr,l,mid,r);
      }
    
    }
    */
 