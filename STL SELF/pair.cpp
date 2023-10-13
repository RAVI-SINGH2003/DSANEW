#include<bits/stdc++.h>
using namespace std;
void print(pair<int,int> p1)
{
    cout << p1.first << " " <<p1.second << endl;
}
int main()
{
  pair<int,int> p1={1,2};
  p1.second = 90;
  print(p1);

  pair<int,int> p2;
  p2 = make_pair(23,3);
  print(p2);

  pair<pair<int,int>,int> p3 = {{1,2},4};
  cout<<p3.first.first<<" "<<p3.first.second<<" "<<p3.second;
  return 0;
}