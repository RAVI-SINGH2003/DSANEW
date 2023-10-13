//Reverse an array using recursion
#include<iostream>
using namespace std;
void print(int *arr ,int n,int i=0)
{
   if(i>=n/2)
   return ;
   swap(arr[i],arr[n-1-i]);
   print(arr,n,++i);
}
int  main()
{
  int arr[]={1,2,3,4,5};
  print(arr,5);
  for(auto i :arr)
  {
      cout<<i<<endl;
  }
}