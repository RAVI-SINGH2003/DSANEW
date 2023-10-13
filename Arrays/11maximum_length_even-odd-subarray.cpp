#include<iostream>
#include <climits>
using namespace std;
int main ()
{
  // int arr[]={0,1,0,1,1,0};
  int arr[]={2,2,2,2,2,2};
  int n=6;
  int count =1;
  int maxi=1;
   for(int i=1;i<n;i++)
     {
       if((arr[i-1]%2==0) &&(arr[i]%2!=0) || (arr[i-1]%2!=0) &&(arr[i]%2==0))
       {
         count++;
         maxi=max(maxi,count);       
         }
       else
         count=1;
     }
  cout<<maxi;
 
}