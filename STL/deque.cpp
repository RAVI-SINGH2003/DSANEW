<<<<<<< HEAD
//dequee is dynamic
//deque - insertion and deletion at both the ends
//deque implementation using multiple fixed static arays;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
  // deque<int> d;
  deque<int> d(5,100);
  d.push_back(1);
  d.push_front(2);
  d.push_front(3);
  for(int  i :d)
  {
      cout<<i<<" ";
  }
//   d.pop_back();
//   d.pop_front(); 
//   for(int  i :d)
//   {
//       cout<<i<<" ";
//   }
  cout<<endl;
  cout<<"First index element : "<<d.at(1)<<endl;
  cout<<"front : "<<d.front()<<endl;
  cout<<"back : "<<d.back()<<endl;
  cout<<"emprty or not ?  : "<<d.empty()<<endl;
  cout<<"Before erase : "<<d.size()<<endl;
  d.erase(d.begin(),d.begin()+1); //deleting first element 
  cout<<"Before erase : "<<d.size()<<endl;
  cout<<"printing elements of deque after erase  : "<<endl;
  for(int i : d)
  {
      cout<<i<<endl;
  }
  cout<<"size before clear  : "<<d.size()<<endl;
  d.clear();
  cout<<"size after clear : "<<d.size()<<endl;
=======
//dequee is dynamic
//deque - insertion and deletion at both the ends
//deque implementation using multiple fixed static arays;
#include<iostream>
#include<deque>
using namespace std;
int main()
{
  deque<int> d;
  deque<int> d(5,100);
  d.push_back(1);
  d.push_front(2);
  d.push_front(3);
  for(int  i :d)
  {
      cout<<i<<" ";
  }
//   d.pop_back();
//   d.pop_front(); 
//   for(int  i :d)
//   {
//       cout<<i<<" ";
//   }
  cout<<endl;
  cout<<"First index element : "<<d.at(1)<<endl;
  cout<<"front : "<<d.front()<<endl;
  cout<<"back : "<<d.back()<<endl;
  cout<<"emprty or not ?  : "<<d.empty()<<endl;
  cout<<"Before erase : "<<d.size()<<endl;
  d.erase(d.begin(),d.begin()+1); //deleting first element 
  cout<<"Before erase : "<<d.size()<<endl;
  cout<<"printing elements of deque after erase  : "<<endl;
  for(int i : d)
  {
      cout<<i<<endl;
  }
  cout<<"size before clear  : "<<d.size()<<endl;
  d.clear();
  cout<<"size after clear : "<<d.size()<<endl;
>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}