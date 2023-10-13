<<<<<<< HEAD
//set stores unique elements
//implementation using bst
//insertion complexity - O(logn)
#include<iostream>
#include<set>
using namespace std;
int main()
{
    set <int> s;
      s.insert(5);
      s.insert(1);
      s.insert(6);
      s.insert(6);
      s.insert(0);
      s.insert(5);
       for(auto i : s)
       {
           cout<<i<<endl;
       }
       cout<<endl;
       set<int> :: iterator it= s.begin();
       it++;
    //    s.erase(5);
       s.erase(it);
       for(auto i : s)
       {
           cout<<i<<endl;
       }
       
       cout<<"5 is present or not  : "<<s.count(5)<<endl;

       set<int>  ::iterator itr = s.find(5);
      cout<<"Value present at itr : "<<*itr<<endl;
      cout<<"printing values using iterator : "<<endl;
      for(auto i = itr;i!=s.end();i++)
      {
          cout<<*i<<endl;
      }
      cout<<"size  : "<<s.size();
      s.erase(5);
      for(int i : s)
     {
       cout<<i<<endl;
    }
    cout<<"empty or not ? : "<<s.empty();
=======
//set stores unique elements
//implementation using bst
//insertion complexity - O(logn)
#include<iostream>
#include<set>
using namespace std;
int main()
{
    set <int> s;
      s.insert(5);
      s.insert(1);
      s.insert(6);
      s.insert(6);
      s.insert(0);
      s.insert(5);
       for(auto i : s)
       {
           cout<<i<<endl;
       }
       cout<<endl;
       set<int> :: iterator it= s.begin();
       it++;
       s.erase(it);
       for(auto i : s)
       {
           cout<<i<<endl;
       }
       
       cout<<"5 is present or not  : "<<s.count(5)<<endl;

       set<int>  ::iterator itr = s.find(5);
      cout<<"Value present at itr : "<<*itr<<endl;
      cout<<"printing values using iterator : "<<endl;
      for(auto i = itr;i!=s.end();i++)
      {
          cout<<*i<<endl;
      }
      cout<<"size  : "<<s.size();
      s.erase(5);
      for(int i : s)
     {
       cout<<i<<endl;
    }
    cout<<"empty or not ? : "<<s.empty();
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}