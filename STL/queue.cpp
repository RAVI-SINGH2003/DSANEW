<<<<<<< HEAD
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main()
{
    queue<string> q;
    q.push("ravi");
    q.push("singh");
    q.push("hi");
    cout<<"First element : "<<q.front()<<endl;
    cout<<"First element : "<<q.back()<<endl;
    q.pop();
    cout<<"First element after pop : "<<q.front()<<endl;
    cout<<"size after  pop : "<<q.size()<<endl;
    cout<<"empty or not : "<<q.empty()<<endl;
    int n= q.size();
  // for(int i=0;i<n;i++)
  // {
  //    cout<<q.front()<<endl;
  //    q.pop();
  // }
=======
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<string> q;
    q.push("ravi");
    q.push("singh");
    q.push("hi");
    cout<<"First element : "<<q.front()<<endl;
    cout<<"First element : "<<q.back()<<endl;
    q.pop();
    cout<<"First element after pop : "<<q.front()<<endl;
    cout<<"size after  pop : "<<q.size()<<endl;
    cout<<"empty or not : "<<q.empty()<<endl;
    int n= q.size();
  for(int i=0;i<n;i++)
  {
     cout<<q.front()<<endl;
     q.pop();
  }

    



>>>>>>> f8b8a2dcf8691bf61c6bc66fd4062749d41f17e1
}