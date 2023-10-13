#include<iostream>
#include <climits>
using namespace std;
int main ()
{
  int arr[]={10,10,60,60,60,60};
  int n= 6;
  int count=1;
  for(int i=1;i<n;i++)
    {
    if(arr[i]==arr[i-1])
    {
      count++;
    }
      else
    {  
      cout<<"Frequency of "<<arr[i-1]<<" : "<<count<<endl;
      count=1;
    }
    
    }
 cout<<"Frequency of "<<arr[n-1]<<" : "<<count<<endl;
}