#include <iostream>
#include<climits>
using namespace std;
int main() {
int arr[]={1,1,1,1};
  int n=4;
  int count =0;
  int maxi,smaxi;
  maxi=smaxi=INT_MIN;
  for(int i=0;i<n;i++)
    {
      if(arr[i]>maxi)
      {
        smaxi=maxi;
        maxi=arr[i];
      }
     
      else if(arr[i]<maxi &&arr[i]>smaxi)
      {
            
          smaxi=arr[i];

      }
      else{
        count++;
      }
    }
  if(count==n-1)
    smaxi=maxi;
  cout<<smaxi;
  }