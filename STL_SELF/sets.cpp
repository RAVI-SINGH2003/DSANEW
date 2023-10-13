#include<bits/stdc++.h>
using namespace std;

//unordered set = hash table tc : o(1) average ,o(n) worst
//set = red black trees tc o(logn)
void print(set<int>&s)
{
    for(int num : s) cout<<num<<" ";
    cout<<"\n";
}
int main()
{
  set<int> s={1,1,2,3};
  s.insert({1,2,3,4,5,5});
  print(s);
  set<int> ::iterator it  = s.find(1);
  if(it!=s.end());
  {
    s.erase(it);
  }
  print(s);
  return 0;
}