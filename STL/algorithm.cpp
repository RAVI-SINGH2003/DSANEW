<<<<<<< HEAD
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
   vector<int> v;
   v.push_back(1);
   v.push_back(3);
   v.push_back(6);
   v.push_back(7);
   cout<<"finding 6 : "<<binary_search(v.begin(),v.end(),6)<<endl;
   cout<<"lower bound : "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
   cout<<"upper bound : "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;
   int a=3,b=5;
   cout<<"max :"<<max(a,b)<<endl;
   cout<<"min : "<<min(a,b)<<endl;
   swap(a,b);
   cout<<"a = "<<a<<" "<<"b= "<<b<<endl;
   string abcd ="abcd";
   reverse(abcd.begin(),abcd.end());
   cout<<"Reversed string  : "<<abcd<<endl;
   rotate(v.begin(),v.begin()+1,v.end());
   for(int i :  v)
   {
       cout<<i<<endl;
   }
   sort(v.begin(),v.end()); // sort is based on intro sort made of quick sort heap sort insertion sort 
   cout<<"Vector after sorting : "<<endl;
  for(int i :  v)
   {
       cout<<i<<endl;
   }

=======
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
   vector<int> v;
   v.push_back(1);
   v.push_back(3);
   v.push_back(6);
   v.push_back(7);
   cout<<"finding 6 : "<<binary_search(v.begin(),v.end(),6)<<endl;
   cout<<"lower bound : "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
   cout<<"upper bound : "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;
   int a=3,b=5;
   cout<<"max :"<<max(a,b)<<endl;
   cout<<"min : "<<min(a,b)<<endl;
   swap(a,b);
   cout<<"a = "<<a<<" "<<"b= "<<b<<endl;
   string abcd ="abcd";
   reverse(abcd.begin(),abcd.end());
   cout<<"Reversed string  : "<<abcd<<endl;
   rotate(v.begin(),v.begin()+1,v.end());
   for(int i :  v)
   {
       cout<<i<<endl;
   }
   sort(v.begin(),v.end()); // sort is based on intro sort made of quick sort heap sort insertion sort 
   cout<<"Vector after sorting : "<<endl;
  for(int i :  v)
   {
       cout<<i<<endl;
   }

>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}