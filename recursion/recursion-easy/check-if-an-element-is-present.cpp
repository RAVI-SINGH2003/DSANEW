bool ispresent(int arr[],int n,int x)
{
    if(n==0)
    return -1;
    if(arr[n-1]==x)
    return true;
    return ispresent(arr,n-1,x);
}