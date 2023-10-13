#include<iostream>
using namespace std;
int main()
{
  int arr[14]={1,1,1,0,0,1,1,1,0,0,0,1,1,1};
  // int arr[14]={0,0,0,1,1,0,0,0,1,1,1,0,0,0};
  int n = 14;
  int ele=arr[0];
  int tobeflipped;
  if(arr[0]==0)
    tobeflipped=1;
  else
    tobeflipped=0;
  
  for(int i=1;i<n;i++)
    {
      if(arr[i]==tobeflipped&&arr[i-1]!=tobeflipped)
      {
        cout<<"FROM"<<i<<" ";
      }
      else if(arr[i]!=tobeflipped&&arr[i-1]==tobeflipped)
      {
        cout<<"TO " <<i-1<<endl;
      }
     
    
    }
 
   if(arr[n-1]==tobeflipped)
      {
        cout<<"TO " <<n-1<<endl;
      }
}