// majority elemet - present >N/2 times in an array
// Moore's voting algorithm
// striver video
 
int majorityElement(int arr[], int n)
{
    int curMaj = arr[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == curMaj)
            count++;
        else
        {
            count--;
            if (count == 0)
            {
                curMaj = arr[i];
                count = 1;
            }
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == curMaj)
            c++;
    }
    return c > n / 2 ? curMaj : -1;
}
// approach 2 nlogn
// int majorityElement(int a[], int size)
// {
//       map<int,int> m;
//       for(int i=0;i<size;i++)
//       {
//           m[a[i]]++;
//           if(m[a[i]]>size/2)
//           return a[i];
//       }
//       return -1;
// }
// approach 3 o(n^2) solution