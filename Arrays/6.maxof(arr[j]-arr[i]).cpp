#include<iostream>
#include <climits>
using namespace std;
//idea : to maintain mini number on left so tat arr[j]-arr[i] is max;
int main ()
{
  int arr[]={10,1,2,4,6,8};
  int n= 6;
  int maxi=arr[1]-arr[0];
  int mini=arr[0] ;  //minimum mana qst number ko
  for(int i=1;i<n;i++)
    { int diff = arr[i] - mini; //phir agle num aur mini ke beech ka diff liya
       maxi= max(maxi,diff); // maxi ko update kiya
       mini=min(mini,arr[i]); //phir mini ko update kiya
    }
  cout<<maxi;
}


