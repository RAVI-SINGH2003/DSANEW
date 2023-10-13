#include<bits/stdc++.h>
using namespace std;
int main()
{
  int  a  = 12;
  for(int i=1;i*i<=12;i++){
    if(a%i==0){
        cout<<i<<"\n";
        if(a/i!=i)
        cout<<a/i<<"\n";
    }
  }

  return 0;

}